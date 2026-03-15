#include <stdio.h>

#include "calc.h"


int main()
{

	int options;

	double a, b, result;


	while(1)
	{
		//user selection
		printf("\nMATH MENU\n");

		printf("1. Add\n");
		printf("2. Subtract\n");
		printf("3. Multiply\n");
		printf("4. Divide\n");
		printf("0. End the App\n");
		printf("Enter Choice\n");
		scanf("%d", &options);


		if (options == 0)
		{
			printf("The Application Has Ended\n");
			break;
		}

		printf("Enter First Number: ");
		scanf("%lf", &a);
		printf("Enter Second Number: ");
		scanf("%lf", &b);


		switch (options)
		{
			case 1: result = add(a, b);      printf("Result: %0.2f\n", result); break;
			case 2: result = subtract(a, b); printf("Result: %0.2f\n", result); break;
			case 3: result = multiply(a, b); printf("Result: %0.2f\n", result); break;
			case 4: result = divide(a, b);   printf("Result: %0.2f\n", result); break;
			default: printf("Invalid Options Seelcted!!\n"); break;
		}
	}
	return 0;
}

	
