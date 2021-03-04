//unit_test.h
// original declarations

#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_1_snazar_init_default_returns_nonNULL(char* buffer, int length);

Status test_2_snazar_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_3_snazar_destroy_object(char* buffer, int length);

Status test_4_snazar_get_size_on_init_c_str_returns_non_0(char*buffer,int length);

Status test_5_snazar_string_get_size(char* buffer, int length);

Status test_6_snazar_string_get_capacity(char*buffer, int length);

Status test_7_snazar_pushback(char*buffer, int length);

Status test_8_snazar_popback(char*buffer, int length);

Status test_9_snazar_concat(char* buffer, int length);

Status test_10_snazar_string_empty_returns_0(char* buffer, int length);

Status test_11_snazar_string_at_returnsNULL(char*buffer, int length);

Status test_12_snazar_string_at_invalid_large_index(char* buffer, int length);

Status test_13_snazar_create_write_file(char* buffer, int length);

Status test_14_snazar_extraction_read_file(char* buffer, int length);

Status test_15_snazar_delete_file(char*buffer, int length);

Status test_16_snazar_compare_identical(char* buffer, int length);

Status test_17_snazar_compare_diff_zebra_Apple(char* buffer, int length);

Status test_18_snazar_compare_diff_apple_Zebra(char* buffer, int length);

Status test_19_snazar_compare_diff_str_right_long(char* buffer, int length);

Status test_20_snazar_compare_diff_str_left_long(char* buffer, int length);

Status test_21_snazar_compare_identical_A_Z(char* buffer, int length);

Status test_22_snazar_compare_identical_a_z(char* buffer, int length);

Status test_23_snazar_compare_identical_Z_A(char* buffer, int length);

Status test_24_snazar_compare_identical_z_a(char*buffer, int length);

Status test_25_snazar_str_empty_returns_1(char* buffer, int length);

Status lab6_checkpoint(char* buffer, int length);

Status lab7_checkpoint1(char* buffer, int length);


#endif

