#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val;
    struct node *next_node;
}node;


void create_node(node *n, int num)
{
    *n = malloc(sizeof(struct node));

    (*n)->val = num;
    (*n)->next_node = NULL;

}

void add_node(node *n1, node *n2)
{
    (*n1)->next_node = (*n2);

}

int main()
{
    node n1;
    node n2;

    create_node(&n1, 10);
    create_node(&n2, 20);

    add_node(&n1, &n2);

    return 0;

}

