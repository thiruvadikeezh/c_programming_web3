#include <stdio.h>

int main()
{
	float fahr, cel;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 1;

	cel = lower;

	while( cel <= upper ){
		fahr = ((9.0/5.0) * cel) + 32.0;

		printf("cel\t fahr\n");
		printf("%3.2f\t%3.2f\n", cel, fahr);

		cel = cel + step;
	}
	return 0;
}


