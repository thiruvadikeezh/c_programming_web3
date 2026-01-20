#include <stdio.h>

int main()
{
	int c;
	int result;

	result = ( (c = getchar()) != EOF);

	printf( " the value of getchar() != EOF: %d\n", result);
	printf(" the value of EOF: %d\n", EOF);

	
	/* c = getchar(); */
	/*while (c != EOF) */
	
	putchar(c=getchar() != EOF);
	while( (c = getchar()) != EOF)
	{
		putchar(c);
	}
}

