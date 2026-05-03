#include <stdio.h>


int main()
{
    int c;

    int nb, nt, nl = 0;

    while( (c = getchar()) != EOF){

        if ( c == ' ')
        {
            ++nb;
        }
        else if (c == '\t')
        {
            ++nt;
        }
        else if (c == '\n')
        {
            ++nl;
        }
    }

    printf("blanks= %d, tabs = %d, new line = %d", nb, nt, nl);
    return 0;
}



