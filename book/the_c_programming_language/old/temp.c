#include <stdio.h>

int main()
{
	int c, i , nwhite, char_len, nnum;

	int chars[20];


	nwhite = char_len = nnum = 0;

	for (i = 0 ; i < 20; i++)
		chars[i] = 0;


	while ((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n' || c == '\t')
		{
			if(char_len>0)
			{
				++chars[char_len];
				char_len = 0;
			}
		}
		else
		{
			++char_len;
		}

	}

		
	for( i = 0; i <20; i++)
	{
		printf("%d", chars[i]);
	}
}

