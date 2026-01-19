#include <stdio.h>

int main()
{
	float fahr, cel;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;

	while ( fahr <= upper) {
		/* cel = 5 * ( fahr - 32 ) / 9; in int calculations*/
		cel = (5.0/9.0) * (fahr-32.0);
		printf("fahr\t cel\n");
		/* printf("%3d\t %3d\n", fahr, cel); for int printing */
		printf("%3.0f\t %3.1f\n", fahr, cel);
		fahr = fahr + step;
	}
}


