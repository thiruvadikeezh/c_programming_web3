#include <stdio.h>
#include <stdlib.h>

#include "sun.h"

void init_center(center_node *c, int capacity)
{
    if( c == NULL || capacity <=0)
    {
        return;
    }

    c->count = 0;
    c->capacity = capacity;

    c->children = malloc(sizeof(node) * capacity);

    if (c->children == NULL)
    {
        printf("allocation faild\n");

        c->capacity =0;

        return;
    }
}

