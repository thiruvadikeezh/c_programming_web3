#include <stdio.h>


typedef struct node{
	int data;
	struct node *prev;
	struct node *next;

}node;

typedef struct
{

	node *head;
	node *tail;
	size_t count;

}list;

void list_init(list *l)
{
	l->head = NULL;
	l->tail = NULL;
	l->count = 0;
}

node *node_create(int value)
{
	node *n = malloc(sizeof(node));

	if(!n)
		return NULL;

	n->data = value;
	n->prev = NULL;
	n->next = NULL;


	return n;
}

void append(
