#include <stdio.h>


int main()
{
	int i;

	char num[] = "12345";
	char space[] = "     ";
	for (i = 5 ; i >= 1; i --)
	{
		printf("%.*s", 5-i, space);
		printf("%.*s\n",i, num);
	}

	return 0;
}
