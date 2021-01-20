/**********************************************************************
Program: Daily 8- Priority Queue heap implementation
Author: Saema Nazar
Date: 12/3/19
Time spent: 2 days
Purpose: implement a priority queue using max-heap. Priority of elements are determined based on their
		keys. Elements with higher keys are at front of queue.
--> PRIORITY_QUEUE.C
***********************************************************************/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

enum status { FAILURE, SUCCESS };
typedef enum status Status;

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

typedef void* PRIORITY_QUEUE;


PRIORITY_QUEUE priority_queue_init_default(void);

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item);

Status priority_queue_service(PRIORITY_QUEUE hQueue);

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus);

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue);

void priority_queue_destroy(PRIORITY_QUEUE* phQueue);

void heapify(PRIORITY_QUEUE hQueue, int index);

//swap values
void swap(int* a, int* b);

void print_heap(PRIORITY_QUEUE hQueue);


#endif