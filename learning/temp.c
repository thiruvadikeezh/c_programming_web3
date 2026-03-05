#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	int id;
	struct Student *next;
}Student;


void insertNode(Student **head, int id)
{
	Student *newNode = malloc(sizeof(Student));

	newNode->id = id;

	Student **indirect = head;

	while( *indirect != NULL)
	{
		indirect = &(*indirect)->next;
	}

	*indirect = newNode;
}


void printNode(Student *head)
{
	Student *temp = head;
	
	while(temp != NULL)
	{
		printf("ID is : %d\n", temp->id);
		temp = temp->next;
	}
}

void freeList(Student *head)
{
	Student *temp;

	while( head != NULL)
	{
		temp = head;
		head = head ->next;
		free(temp);
	}
}



int main()
{
	Student *head = NULL;

	insertNode(&head, 101);

	insertNode(&head, 102);

	printNode(head);

	freeList(head);

	return 0;
}

