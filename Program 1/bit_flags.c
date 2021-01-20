/***********************************************************
/////////////////////RESUBMISSION: PROGRAM 1/////////////////////
File: bit_flags.c
Author: Saema Nazar
Date: 9/26/19
Effort: 3 days
Purpose: create a bit collection data structure using an array 
Interface proposal: <answer the last question in the specification>
***********************************************************/

#include <stdio.h>
#include "bit_flags.h"
#include <stdlib.h>

typedef struct bit_flags {
	int size;
	int capacity;
	int* bitData;
} Bit_flags; 


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits) {
	Bit_flags* pBit_flags;
	if (number_of_bits <= 0) {
		printf("Error: Number of bits should be a positive integer.\n");
		return NULL;
	}
	pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
	if (pBit_flags == NULL) {
		printf("Error: memory could not be allocated.\n");
		return NULL;
		}
	pBit_flags->size = number_of_bits;
	pBit_flags->capacity = number_of_bits;
	pBit_flags->bitData = (int*)malloc(sizeof(int)*pBit_flags->capacity);
	if (pBit_flags->bitData == NULL) {
		printf("Error: memory allocation for bit data failed.\n");
		return NULL;
	}
	*pBit_flags->bitData = 0;
	return pBit_flags;
}


Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position) {
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int* tmp = NULL;

	while (pBit_flags->capacity < flag_position) {
		pBit_flags->capacity *= 2;
		tmp = (int*)malloc(sizeof(int) * pBit_flags->capacity);
		if (tmp == NULL) {
			printf("Error: Memory allocation for resize failed.\n");
			return FAILURE;
			}
		*tmp = *(pBit_flags->bitData);
		free(pBit_flags->bitData);
		pBit_flags->bitData = tmp;
	}
	int bitNum = flag_position;
	flag_position = flag_position / pBit_flags->capacity;
	pBit_flags->bitData[flag_position] |= (bitNum % pBit_flags->capacity);
	pBit_flags->size = pBit_flags->size - 1;
	return SUCCESS;

}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position) {
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int* tmp = NULL;

	while (pBit_flags->capacity < flag_position) {
		pBit_flags->capacity *= 2;

		tmp = (int*)malloc(sizeof(int) * pBit_flags->capacity);
		if (tmp == NULL) {
			printf("Error: Malloc in unset function failed.\n");
			return FAILURE;
		}
		*tmp = *(pBit_flags->bitData);
		free(pBit_flags->bitData);
		pBit_flags->bitData = tmp;
	}
	int bitNum = flag_position;
	flag_position = flag_position / pBit_flags->capacity;
	pBit_flags->bitData[flag_position] &= ~(1 << (bitNum % (pBit_flags->capacity)));

	pBit_flags->size = pBit_flags->size + 1;
	return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position) {
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;

	if ((flag_position > pBit_flags->capacity) || flag_position < 0) {
		return -1;
	}

	flag_position = flag_position / pBit_flags->capacity;

	if ((pBit_flags->bitData[flag_position] >> flag_position) & 1) {
		return (pBit_flags->bitData[flag_position]);
	}

}

int bit_flags_get_size(BIT_FLAGS hBit_flags) {
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return (pBit_flags->size);
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags) {
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return (pBit_flags->capacity);
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags) {
	Bit_flags* pBit_flags = (Bit_flags*)phBit_flags;
	if (pBit_flags != NULL) {
		free(pBit_flags->bitData);
		free(pBit_flags);
	}
	*phBit_flags = NULL;
}

