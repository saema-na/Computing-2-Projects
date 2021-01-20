/**********************************************************************
Program: Program 3- Number Filter
Author: Saema nazar
Date: 11/23/19
Time spent: 2 days
Purpose: take in an unknown number of integer input values, remove repeats, and output the inputs after sorting
***********************************************************************/


#pragma once
#include <stdio.h>
#include "status.h"

void quick_sort(int a[], int size);

typedef void* VECTOR;

VECTOR vector_init_default(void);

Status vector_push_back(VECTOR, int);

void vector_destroy(VECTOR*);

int is_repeat(VECTOR, int);

void swap(int* a, int* b);

void sort_list(VECTOR hVector);

void print_list(VECTOR hVector);