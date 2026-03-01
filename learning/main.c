#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student
{
	int id;
	char name[50];
	float marks;
	struct Student *next; // linked list pointer
} Student;

void insertStudent(Student **head, int id, char*name, float marks)
{
	Student *newNode = malloc(sizeof(Student));

	newNode->id = id;
	strcpy(newNode->name, name);
	newNode->marks = marks;
	newNode->next= NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		Student *temp = *head;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}

}

void printList(Student *head)
{
	Student *temp = head;
	
	while(temp != NULL)
	{
		printf("ID: %d\n", temp->id);
		printf("Name: %s\n", temp->name);
		printf("Marks %.2f\n", temp->marks);

		temp =  temp->next;
	}

}

void freeList(Student *head)
{
	Student *temp;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void removeNode(Student **head, int id)
{
	if (*head == NULL)
		return;
	
	Student *temp = *head;
	Student *prev = NULL;

	if (temp->id == id)
	{
		*head = temp->next;
		free(temp);
		return;

	}

	while (temp != NULL && temp->id != id)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return;

	prev->next = temp->next;

	free(temp);
}

int main()
{
	Student *head = NULL;

	insertStudent(&head, 101, "markiplier", 75.0);
	insertStudent(&head, 102, "Logtiech", 88.0);
	insertStudent(&head, 103, "Nvidia", 92.0);


	printf("Printing A Node \n");
	printList(head);

	printf("Deleting A Node\n\n");
	removeNode(&head, 101);
	printList(head);

	freeList(head);

	return 0;

}
