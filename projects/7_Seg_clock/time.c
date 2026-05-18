#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{

	time_t result;
	time_t pointer;

	result = time(&pointer);

	char *lctime = asctime(localtime(&result));

	printf("the time is %ld\n", result);
	printf(" the pointer is %ld\n", pointer);
	printf("the formatted time is %s\n", lctime);
	return 0;

}

