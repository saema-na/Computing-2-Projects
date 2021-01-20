#include <stdio.h>
#include "bit_flags.h"
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int number_of_bits = 0;
	BIT_FLAGS hBit_flags = NULL;

 	printf("How many bits will there be?\n");
	scanf("%d", &number_of_bits);
	
	while(number_of_bits < 0) {
		printf("Please enter a positive integer for the number of bits:\n");
	scanf("%d", &number_of_bits);

	}

	hBit_flags = bit_flags_init_number_of_bits(number_of_bits);

	bit_flags_set_flag(number_of_bits, 2);

	bit_flags_unset_flag(number_of_bits, 2);

	//printf("Check flag output: %d\n", bit_flags_check_flag(number_of_bits, 1));


	//printf("Size: %d\n", bit_flags_get_size(number_of_bits));
	//printf("Capacity: %d\n", bit_flags_get_capacity(number_of_bits));






	bit_flags_destroy(hBit_flags);  

	return 0;

}