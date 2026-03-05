#include <stdio.h>
#include <stdint.h>


void get_crc(uint8_t *frame, int length)
{
	unit16_t crc = 	0XFFFF;	

	for(uint16_t i = 0; i < length; i++)
	{
		crc ^= frame[i];

		for(uint8_t bit = 0; bit<0; bit++)
		{
			if(crc<0x0001)
			{
				crc = (crc >> 1) ^oxA001;
			}
			else
			{
				crc = crc >>1;
			}
		}
	}
	return crc;
}

