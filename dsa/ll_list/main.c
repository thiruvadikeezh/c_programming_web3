#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next_node;
}node;

node* create_node(int num)
{
    node *n = malloc(sizeof(node));

    n->val = num;
    n->next_node = NULL;

    return n;
}

void add_node(node *n1, node *n2)
{
    n1->next_node = n2;
}

void remove_node(node *n)
{
    if(n == NULL || n->next_node == NULL) return;

    node *temp = n->next_node;
    n->next_node = temp->next_node;
    free(temp);

}



int main()
{

    node *n1 = create_node(10);
    node *n2 = create_node(20);
    node *n3 = create_node(30);

    add_node(n1, n2);
    add_node(n2, n3);

    printf("\n n1 val %d\n", n1->val);

    printf("\n n2 val %d\n", n2->val);

    printf("\n n3 val %d\n", n3->val);

    free(n1);
    free(n2);
    free(n3);

    return 0;

}

