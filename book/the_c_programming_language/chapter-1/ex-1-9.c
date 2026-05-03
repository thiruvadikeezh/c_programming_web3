#include <stdio.h>


int main()
{
    int c;

    int nb, nt, nl, prev_space = 0;

    while( (c = getchar()) != EOF){
        if (c == ' ')
        {
            if (!prev_space)
            {
                putchar(c);
                prev_space = 1;
            }
        }
        else
        {
            putchar(c);
            prev_space = 0;
        }
    }

    return 0;
}



