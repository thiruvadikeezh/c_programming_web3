#include <stdio.h>

void ptr_test( int *num)
{

	*num = *num + *num ;
}

int main()
{
	int number = 10 ;

	ptr_test(&number);
	printf("%d", number);
	return 0;
}


