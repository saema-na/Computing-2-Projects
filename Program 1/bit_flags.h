/***********************************************************
/////////////////////RESUBMISSION: PROGRAM 1/////////////////////
File: bit_flags.h
Author: Saema Nazar
Date: 9/26/19
Effort: 3 days
Purpose: create a bit collection data structure using an array
Interface proposal: <answer the last question in the specification>
***********************************************************/

#ifndef BIT_FLAGS_H
#define BIT_FLAGS_H
#include "status.h"

typedef void* BIT_FLAGS;


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits);


Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position);


Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position);


int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);


int bit_flags_get_size(BIT_FLAGS hBit_flags);


int bit_flags_get_capacity(BIT_FLAGS hBit_flags);


void bit_flags_destroy(BIT_FLAGS* phBit_flags);


#endif
