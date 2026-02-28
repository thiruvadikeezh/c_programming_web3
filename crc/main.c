#include <stdio.h>
#include <stdint.h>

uint16_t crc16(uint8_t *data, uint16_t length)
{
	uint16_t crc = 0xFFFF;

	for (uint16_t i = 0; i< length; i++)
	{
		crc ^= data[i];

		for(uint8_t bit = 0; bit < 8; bit ++)
		{
			if (crc & 0x0001)
			{
				crc = (crc >> 1) ^ 0xA001;
			}
			else
			{
				crc = crc >>1;
			}

		}
		
	}

	return crc;

}

int main()
{
	uint8_t frame[] = {0x01, 0x03, 0x02, 0x00, 0x0B};

	uint16_t st = crc16(frame, 5);

	printf("%u\n", st);

	return 0;
}




