/**********************************************************************
Program: Daily 8- Priority Queue heap implementation
Author: Saema Nazar
Date: 12/3/19
Time spent: 2 days
Purpose: implement a priority queue using max-heap. Priority of elements are determined based on their
		keys. Elements with higher keys are at front of queue.
--> PRIORITY_QUEUE.C
***********************************************************************/

#ifndef PRIORITY_QUEUE_C
#define PRIORITY_QUEUE_C
#include <stdio.h>
#include "priority_queue.h"


struct node {
	int prty;
	int data;
	int size;
	int capacity;
};
typedef struct node Node;

struct queue {
	Node* heap;
	int front;
};
typedef struct queue Queue;


PRIORITY_QUEUE priority_queue_init_default(void) {
	Queue* pQueue = NULL;

	pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue == NULL) {
		printf("Error: Could not allocate memory for pQueue upon initialization\n");
		exit(1);
	}
	pQueue->heap = (Node*)malloc(sizeof(Node)*2);
	if (pQueue->heap == NULL) {
		printf("Error: Could not allocate memory for heap upon initialization\n");
		exit(1);
	}
		pQueue->front = 0;
		pQueue->heap->size = 0;
		pQueue->heap->capacity = 2;
		pQueue->heap->prty = 0;

	return pQueue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item) {
	Queue* pQueue = (Queue*)hQueue;
	Node* tmp = NULL;
	Status status;
	if (pQueue->heap->size >= pQueue->heap->capacity) {
		tmp = (Node*)malloc(sizeof(Node) * pQueue->heap->capacity * 2);
		if (tmp == NULL) {
			printf("Error: Couldn't allocate space for resize operation.\n");
			exit(1);
		}
		for (int i = 0; i < pQueue->heap->size; ++i) {
			tmp[i] = pQueue->heap[(pQueue->front + i) % pQueue->heap->capacity];
		}
		free(pQueue->heap);
		pQueue->heap = tmp;
		pQueue->heap->capacity *= 2;
		pQueue->front = 0;
	}
	pQueue->heap[pQueue->heap->size].data = data_item;
	pQueue->heap[pQueue->heap->size].prty = priority_level;


	//	fix-up: adjust queue to satisfy max-heap property again
	int i = pQueue->heap->size;
	while ((i >= 0) && (pQueue->heap[i].prty > pQueue->heap[(i-1)/2].prty)){
		swap(&(pQueue->heap[i].prty), &(pQueue->heap[(i-1)/2].prty));
		swap(&(pQueue->heap[i].data), &(pQueue->heap[(i-1)/2].data));

		i = (i - 1) / 2;
	}
	pQueue->heap->size++;
	status = SUCCESS;
	return status;
	}
	
Status priority_queue_service(PRIORITY_QUEUE hQueue) {
	Queue* pQueue = (Queue*)hQueue;
	if (pQueue == NULL || pQueue->heap->size == 0) {
		return FAILURE;
	}
	//removing highest priority node & replacing with lowest/rightmost
	int size = pQueue->heap->size;
	int maxData = pQueue->heap[0].data;
	pQueue->heap[0].data = pQueue->heap[size-1].data;
	pQueue->heap[0].prty = pQueue->heap[size-1].prty;
	pQueue->heap->size--;
	
	//heapify to maintain max-heap property after removal of max
	heapify(hQueue, 0);
	heapify(hQueue, 0);

	return SUCCESS;
}


int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus) {
	Queue* pQueue = (Queue*)hQueue;
	int front = 0;

	if (((pQueue->heap->size == 0) || (pQueue == NULL) && *pStatus != NULL)){
		*pStatus = FAILURE;
		front = pQueue->heap[0].data;
		return front;
	}

	if ((pQueue->heap->size != 0) && *pStatus != NULL){
		front = pQueue->heap[0].data;
		*pStatus = SUCCESS;
		return front;
	}
	return front;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue) {
	Queue* pQueue = (Queue*)hQueue;
	if (pQueue->heap->size == 0 || (pQueue == NULL)){
		return TRUE;
	}
	return FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue) {
	Queue* pQueue = (Queue*)phQueue;
	free(pQueue->heap);
	*phQueue = NULL;
}

void heapify(PRIORITY_QUEUE hQueue, int index) {
	Queue* pQueue = (Queue*)hQueue;
	int maxIndex = index;
	int leftIndex = 2 * index + 1;
	int rightIndex = 2 * index + 2;

	if((pQueue->heap[index].prty < pQueue->heap[leftIndex].prty) && leftIndex < (pQueue->heap->size)){
		maxIndex = leftIndex;
	}
	
	if((pQueue->heap[index].prty < pQueue->heap[rightIndex].prty) && rightIndex < (pQueue->heap->size)){
		maxIndex = rightIndex;
	}
	
	if (maxIndex != index) {
		swap(&(pQueue->heap[index].data), &(pQueue->heap[maxIndex].data));
		swap(&(pQueue->heap[index].prty), &(pQueue->heap[maxIndex].prty));
		heapify(hQueue, maxIndex);
	}	
}

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_heap(PRIORITY_QUEUE hQueue) {
	Queue* pQueue = (Queue*)hQueue;

	for (int i = 0; i < (pQueue->heap->size); i++){
		printf("Key: %d\tData: %d ", pQueue->heap[i].prty, pQueue->heap[i].data);
		printf("\n");
	}
		printf("\n");
}
#endif