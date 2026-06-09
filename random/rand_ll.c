#include <stdio.h>


typedef struct node{
	int num;
	struct node *nodes;
}node;




void create_node( node *n, int val)
{
	n->num = val;

	n->nodes = NULL;

}


void join_node( node *n1 , node *n2 )

{
	n1->nodes = n2;

}

int main()
{
	node n1;

	node n2;

	create_node(&n1, 10);
	create_node(&n2, 20);

	join_node(&n1, &n2);

	printf(" node 1 val is %d \n node 2 val is %d \n", n1.num, n2.num);

	printf(" node 2 value access from n1 %d\n ", n1.nodes->num);

	return 0;

}

