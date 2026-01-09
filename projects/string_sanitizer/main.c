#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char word[] = "AT+DATA=  123 , 45 , OK\r\n";



/* uart_buf now contains:
   "AT+DATA=123,45,OK"
*/


void str_cleaner(char *buffer)
{
	char *read = buffer;
	char *write = buffer;

	while(*read != '\0')
	{
		if (*read != ' ' && *read != '\r' && *read != '\n')
		{
			*write = *read;
			write++;
		}
		read++;
	}

	*write = '\0';
}

int main(void)
{
	str_cleaner(word);

	printf(" the string is %s", word );
	printf("\n");

	return 0;
}


/* uart_buf now contains:
   "AT+DATA=123,45,OK"
*/




