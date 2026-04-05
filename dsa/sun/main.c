#include <stdio.h>

#include "sun.h"


int main()
{

    center_node c;

    init_center(&c, 3);

    printf("Count = %d\n", c.count);

    printf("capacity = %d\n", c.capacity);

    return 0;
}

