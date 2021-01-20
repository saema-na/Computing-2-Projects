#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <stdlib.h>

void stack_push(struct Stack** head, int item) {
	struct Stack* newHead = (struct Stack*)malloc(sizeof(struct Stack));
	if (newHead == NULL) {
		exit(1);
	}
	newHead->data = item;
	newHead->next = *head;
	*head = newHead;
}

int stack_pop(struct Stack** head) {
	struct Stack* top;
	char ch;
	if (*head == NULL) {
		getchar();
		exit(1);
	}
	else {
		top = (*head);
		ch = top->data;
		*head = top->next;
		free(top);
		return ch;
	}

}

int isEmpty(struct Stack* head) {	//return 1 if top of stack is empty
	if (head == NULL) {
		return 1;
	}
	else if (head != NULL) {
		return 0;
	}
	
}
int isMatching(char item1, char item2) {
	if (item1 == '{' && item2 == '}') {
		return 1;
	}

	else if (item1 == '(' && item2 == ')') {
		return 1;
	}
	else if (item1 == '[' && item2 == ']') {
		return 1;
	}

	else { return 0; }
}


int isCorrect(char str[]) {
	struct Stack* head = NULL;
	int n = 0;

	while (n < strlen(str)+1) {

		//if str[n] is left marker, push onto stack
		if (str[n] == '(' || str[n] == '{' || str[n] == '[') {
			stack_push(&head, str[n]);

		}
		//if str[n] is right marker, check top
		if (str[n] == ')' || str[n] == '}' || str[n] == ']') 
		{			

			//if top doesnt exist/stack empty, return NOT MATCH to main
			if (isEmpty(head) == 1) 
			{
				return 0;
			}

			//match = 1 if char in stack top matches current right char
			char tempTop = check_top(head);
			int match = isMatching(tempTop, str[n]);

			if (match == 0)  
			{
				return 0;
			}
			else	//if not a match, clear stack
			{
				stack_pop(&head);
			}
		}

		n++;
	}
		//if stack is empty
		if (isEmpty(head)) {
			return 1;
		}
		//if stack has unmatched/leftover markers
		else return 0;
	}


char check_top(struct Stack* top) {	//return char at top of stack, used to compare chars
	return (top->data);
}