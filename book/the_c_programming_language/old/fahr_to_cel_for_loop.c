#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 5

int main()
{
	int fahr;

	/*for( fahr = 0; fahr <= 300; fahr = fahr + 20 )*/
	for ( fahr = UPPER ; fahr >= LOWER; fahr = fahr - STEP)
	{
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
	}
}

