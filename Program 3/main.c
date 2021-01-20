/**********************************************************************
Program: Program 3- Number Filter
Author: Saema nazar
Date: 11/23/19
Time spent: 2 days
Purpose: take in an unknown number of integer input values, remove repeats, and output the inputs after sorting
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int main(int argc, char* argv[]) {
	VECTOR hVector = NULL;
	hVector = vector_init_default();
	
	int inputVal = 0;
	int repeatVal;
	scanf("%d", &inputVal);
	while (inputVal != -1) {
		
		repeatVal = is_repeat(hVector, inputVal);
		if (repeatVal != 1) {
			vector_push_back(hVector, inputVal);
		}
		scanf("%d", &inputVal);

	}
	sort_list(hVector);
	print_list(hVector);

	vector_destroy(&hVector);

	return 0;
}