/**********************************************************************
Program: Daily 6 --> reverse a linked list
Author: Saema Nazar
Date: 9/30/19
Time spent: ~1.5 h
Purpose: The purpose of this program is to write a function that reverses the contents of a linked list.
***********************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
void reverse_linkedlist(Node** head);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));	//temp holds memory address of newly created space
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;		//data in new space is = to i
		temp->next = head;	//pointer attached to temp variable is = to first element's mem location
		head = temp;		//link Head to newly created temp
	}

	//call your function to reverse the list (should work for any list given the head node).
	reverse_linkedlist(&head);

	//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

//Define your function here
void reverse_linkedlist(Node** head) {

	Node* previous = NULL;
	Node* next;
	Node* current = *head;

	while (current != NULL) {	//until the end of the linked list isn't reached

		next = current->next;	//ptr next = next element after current element

		current->next = previous;	//the next element after current = previous
		
		previous = current;			//previous element = current --> moving backwards
		
		current = next;			
	}

	*head = previous;	//content of the head node now equals previous
	
} 
