#include <stdio.h>


typedef struct pair
{
	char key[100];

	char value[100];
}pair;

pair pairs[10];

int count = 0;

int main(){

	char json_text[] = "{\"name\": \"ALice\", \"Friend\": \"Shiva\", \"Age\": 30 }";


	printf("the json input is %s\n", json_text);


	char *p = json_text;

	while (*p)
	{
		while(*p && *p != '"')
		{
			p++;
		}

		p++;

		int i = 0;

		while (*p && *p != '"'){
			pairs[count].key[i++] = *p;
			p++;
		}
		p++;

		pairs[count].key[i] = '\0';

		while (*p && *p != ':')
			p++;
		
		p++;

		while(*p == ' ')
			p++;

		i = 0;

		if (*p == '"')
		{
			p++;

			while(*p && *p != '"')
			{
				pairs[count].value[i++] = *p;
				p++;
			}

			p++;
			pairs[count].value[i] = '\0';

		}
		else
		{

			while(*p && *p != ',' && *p != '}')
			{
				pairs[count].value[i++] = *p;
				p++;
			}

			pairs[count].value[i] = '\0';
		}

		count++;


		while(*p && *p != ',' && *p != '}')
		{
			p++;
		}
		
		if (*p == ',')
		{
			p++;
		}
		else if ( *p == '}')
		{
			break;
		}
	}
	for ( int i = 0; i < count ; i++)
	{
		printf("%s : %s\n", pairs[i].key, pairs[i].value);
	}


	return 0;
}
