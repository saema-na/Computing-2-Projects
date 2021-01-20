#ifndef stack_h
#define stack_h


struct Stack {
	char data;

	struct Stack* next;
};

int isCorrect(char str[]);	//used in main.c: calls other fxns

void stack_push(struct Stack** head, int item);	//push new item onto stack

int stack_pop(struct Stack** head);	//pop node off stack

int isEmpty(struct Stack* head);	//return true if head is null

int isMatching(char item1, char item2);	//return true if 

char check_top(struct Stack* top);


#endif