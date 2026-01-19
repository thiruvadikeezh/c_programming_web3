#include <stdio.h>
#include <string.h>

char word[] = "this - is a test program \r\n";


void string_sanitizer(char *buffer)
{
	char *read = buffer;
	char *write = buffer;

	while ( *read != '\0' )
	{
		if (*read != '-' && *read != '\r' && *read != '\n' && *read != ' ')
		{
			*write = *read;
			write++;
		}
		read++;
	}

	*write = '\0';
}

int main()
{

	string_sanitizer(word);
	printf("the string i have worked is %s\n", word);

	return 0;
}

