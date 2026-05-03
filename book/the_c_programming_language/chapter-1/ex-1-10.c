#include <stdio.h>


int main()
{
    int c;

    int nb, nt, nl, prev_space = 0;

    while( (c = getchar()) != EOF){

        if ( c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\b')
        {
            printf("\\b");
        }
        else if (c == '\\')
        {
            printf("\\\\");
        }
        else
        {
            putchar(c);
        }

    }

    return 0;
}



