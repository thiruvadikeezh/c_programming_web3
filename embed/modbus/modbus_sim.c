#include <stdio.h>
#include <stdint.h>


uint16_t modbus_crc(uint8_t *buf, uint16_t len)
{
	uint16_t crc = 0xFFFF;


	for(uint16_t pos = 0; pos < len; pos++)
	{
		crc ^= buf[pos];


		for (int i = 0; i< 8; i++)
		{
			if(crc &1)
			{
				crc >>= 1;
				crc ^= 0xA001;
			}
			else
				crc >>= 1;
		}

	}
	return crc;

}


// ----------------------SLAVE_MEMORY------------------
//
uint16_t holding_registers[10] = {
	100, 200, 300, 400, 500,
	600, 700, 800, 900, 1000
};



// -------------------------- MASTER BUILDS REQUEST-------------------------

int build_read_request(uint8_t slave_id,
		uint16_t start_addr,
		uint16_t quantity,
		uint8_t *frame)
{
	frame[0] = slave_id;
	frame[1] = 0x03;

	frame[2] = (start_addr >> 8) & 0xFF;
	frame[3] = start_addr & 0xFF;

	frame[4] = (quantity >> 8) & 0xFF;
	frame[5] = quantity & 0xFF;

	uint16_t crc = modbus_crc(frame, 6);
	frame[6] = crc & 0xFF;
	frame[7] = (crc >> 8) & 0xFF;

	return 8;
}


int slave_process(uint8_t *request, uint8_t *response)
{
	uint16_t crc_received = request[6] | (request[7] << 8);
	uint16_t crc_calc = modbus_crc(request, 6);

	if (crc_received != crc_calc)
	{
		printf("CRC ERROR\n");
		return 0;
	}

	uint8_t slave_id = request[0];
	uint8_t function = request[1];

	uint16_t start_addr = (request[2] << 8) | request[3];
	uint16_t quantity = (request[4] << 8) | request[5];

	response[0] = slave_id;
	response[1] = function;
	response[2] = quantity * 2;

	for(int i = 0; i < quantity; i++)
	{
		// uint16_t value = holding_registers[start_addr + i];

		uint16_t base = 0x8FF0;
		uint16_t index = (start_addr - base) + i;
		uint16_t value = holding_registers[index];

		response[3 + i*2] = (value >> 8) & 0xFF;
		response[4 + i*2] = value & 0xFF;
	}


	uint16_t crc = modbus_crc(response, 3 + quantity*2);

	int len = 3+ quantity*2;

	response[len] = crc & 0xFF;
	response[len + 1] = (crc >> 8) & 0xFF;

	return len +2;
}


void master_parse(uint8_t *response)
{
	uint8_t slave_id = response[0];
	uint8_t function = response[1];
	uint8_t byte_count = response[2];


	printf("\nMaster Received Response:\n");

	for(int i = 0; i < byte_count/2; i++)
	{
		uint16_t value = (response[3 + i*2] << 8) | response[4 + i*2];

		printf("Request %d value = %u\n", i, value);
	}
}



int main()
{
	uint8_t request[8];
	uint8_t response[256];


	int req_len = build_read_request(1, 0x8FF0, 29, request);
	printf("\nModbus request Frame:\n");

	for(int i = 0; i < req_len; i++)
		printf("%02X ", request[i]);
	printf("\n");

	int resp_len = slave_process(request, response);

	printf("\nResponse Frame:\n");

	for(int i = 0; i < resp_len; i++)
		printf("%02X ", response[i]);
	printf("\n");

	master_parse(response);

	return 0;
}


