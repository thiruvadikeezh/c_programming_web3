#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;


    lower = 0;

    upper = 300;

    step = 20;

    celsius = lower;
    printf("celsius\t fahr\n");

    while (celsius < upper)
    {

        fahr = 32 + ((9 * (celsius)/5));

        printf("%5f\t %5f\n", celsius, fahr);

        celsius = celsius + step;
    }
}

