/**********************************************************************
Program: Daily 8- Priority Queue heap implementation
Author: Saema Nazar
Date: 12/3/19
Time spent: 2 days
Purpose: implement a priority queue using max-heap. Priority of elements are determined based on their
		keys. Elements with higher keys are at front of queue.
--> MAIN.C
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"


int main(int agrc, char* argv[]) {
	int value = 0;
	int key = 0;

	PRIORITY_QUEUE hQueue = NULL;
	Status pStatus;

	hQueue = priority_queue_init_default();
	
	priority_queue_insert(hQueue, 5, 23);
	priority_queue_insert(hQueue, 10, 19);
	priority_queue_insert(hQueue, 13, 32);
	priority_queue_insert(hQueue, 40, 18);
	priority_queue_insert(hQueue, 8, 12);
	priority_queue_insert(hQueue, 21, 63);
	priority_queue_insert(hQueue, 51, 27);
	priority_queue_insert(hQueue, 77, 14);


	printf("Heap after all inputs inserted:\n");
	print_heap(hQueue);

	printf("\nIs priority queue empty: %d\n", priority_queue_is_empty(hQueue));

	priority_queue_service(hQueue);
	printf("\nPriority Queue after 1 max removal:\n");
	print_heap(hQueue);
	
	printf("\nPriority Queue Front Data: %d\n", priority_queue_front(hQueue, &pStatus));
	printf("pStatus after priority_queue_front function call: %d\n\n", pStatus);

	priority_queue_destroy(&hQueue);
	if (hQueue == NULL) {
		printf("\nPriority Queue successfully destroyed.\n");
	}

	return 0;
}