/**********************************************************************
Program: Program 3- Number Filter
Author: Saema nazar
Date: 11/23/19
Time spent: 2 days
Purpose: take in an unknown number of integer input values, remove repeats, 
and output sorted list
***********************************************************************/

#include <stdio.h>
#include "sort.h"

struct vector {
	int size;
	int capacity;
	int* data;
};
typedef struct vector Vector;


void quick_sort(int a[], int size) {
	
	int* left;
	int* right;
	int* pivot;
	pivot = &a[0];
	left = a;
	right = a + size - 1;
	if (size < 2)
		return;
	while (left < right) {
		while (right > left && *right > * pivot)
			right--;
		while (left < right && *left <= *pivot)
			left++;
		if (left != right)
			swap(left, right);
	}
	swap(pivot, left);
	quick_sort(a, left - a);
	quick_sort(&a[left - a + 1], &a[size - 1] - right);
}

VECTOR vector_init_default(void) {
	Vector* pVector = NULL;
	pVector = (Vector*)malloc(sizeof(Vector));
	if (pVector != NULL) {
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);
		if (pVector->data == NULL) {
			free(pVector);
			pVector = NULL;
		}
	}
	return pVector;
}

Status vector_push_back(VECTOR hVector, int item) {
	Vector* pVector = (Vector*)hVector;
	int* tmp;
	int i;
	if (pVector->size >= pVector->capacity) {
		tmp = (int*)malloc(sizeof(int) * pVector->capacity * 2);
		if (tmp == NULL) {
			printf("Error: Could not resize capacity in pushback.\n");
			return FAILURE;
		}
		for (i = 0; i < pVector->capacity; i++) {
			tmp[i] = pVector->data[i];
		}
		free(pVector->data); pVector->data = tmp;
		pVector->capacity *= 2;
	}
	pVector->data[pVector->size] = item;
	pVector->size++;
	return SUCCESS;
}


void vector_destroy(VECTOR* phVector) {
	Vector* pVector = (Vector*)* phVector;
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}

int is_repeat(VECTOR hVector, int inputVal){
	Vector* pVector = (Vector*)hVector;
	int i = 0;
	
	for (i = 0; (i < pVector->size); i++) {
		if (pVector->data[i] == inputVal) {
			return 1;
		}
	}
	
	return 0;

}

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort_list(VECTOR hVector) {
	Vector* pVector = (Vector*)hVector;

	quick_sort((pVector->data), (pVector->size));
}

void print_list(VECTOR hVector) {
	Vector* pVector = (Vector*)hVector;
	int i = 0;
	for (i = 0; i < pVector->size; i++) {
		int data = pVector->data[i];
		printf("%d\n", data);
	}

}