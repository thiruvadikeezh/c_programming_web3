#include <stdio.h>




struct Node {
	int data;
	struct Node *next;
};



void remove_node(struct Node **head_ref, struct Node *entry)
{
	struct Node **indirect = head_ref;


	while ( *indirect != NULL && *indirect != entry)
		indirect = &(*indirect)->next;

	if(*indirect == NULL)
		return;

	*indirect = entry->next;
}


int main()
{
	struct Node n1, n2, n3;

	n1.data = 1;
	n2.data = 2;
	n3.data = 3;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	struct Node *head = &n1;

	printf("Before:\n");

	struct Node *temp = head;
	while(temp) {

		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	

	remove_node(&head, &n2);

	printf("\nAfter Removing 2:\n");

	temp = head;


	while( temp) {
		printf("%d ->", temp->data);
		temp = temp -> next;
	}
	printf(" NULL\n");

	return 0;
}

