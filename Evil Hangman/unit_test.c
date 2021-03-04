
/* UNIT_TEST.c -->main program
return_type (*function_name)(arguments)"
*/

// ORIGINAL UNIT_TEST.C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"


int main(int argc, char* argv[]){
  Status (*tests[])(char*, int) =
    {                
      test_1_snazar_init_default_returns_nonNULL,
      test_2_snazar_get_size_on_init_default_returns_0,
      test_3_snazar_destroy_object,
      test_4_snazar_get_size_on_init_c_str_returns_non_0,
      test_5_snazar_string_get_size,
      test_6_snazar_string_get_capacity,
      test_7_snazar_pushback,
      test_8_snazar_popback,
      test_9_snazar_concat,
      test_10_snazar_string_empty_returns_0,
      test_11_snazar_string_at_returnsNULL,
      test_12_snazar_string_at_invalid_large_index,
      test_13_snazar_create_write_file,
      test_14_snazar_extraction_read_file,
      test_15_snazar_delete_file,
      test_16_snazar_compare_identical,
      test_17_snazar_compare_diff_zebra_Apple,
      test_18_snazar_compare_diff_apple_Zebra,
      test_19_snazar_compare_diff_str_right_long,
      test_20_snazar_compare_diff_str_left_long,
      test_21_snazar_compare_identical_A_Z,
      test_22_snazar_compare_identical_a_z,
      test_23_snazar_compare_identical_Z_A,
      test_24_snazar_compare_identical_z_a,
      test_25_snazar_str_empty_returns_1,

            lab6_checkpoint,
            lab7_checkpoint1,
    };

  
  int number_of_functions = sizeof(tests)/sizeof(tests[0]);
  int i = 0;
  char buffer[500];
  int success_count = 0;
  int failure_count = 0;

  for(i=0; i< number_of_functions; i++){
    if(tests[i](buffer, 500) == FAILURE){
         printf("FAILED  Test %d failed miserably.\n", (1+i));
         printf("\t%s\n", buffer);
      failure_count++;
    }
    else {
      // printf("PASS: Test %d passed\n", (i+1));
      // printf("\t%s\n", buffer);
      success_count++;
    }
  }
  printf("Total number of tests: %d\n", number_of_functions);
  printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);
 

  return 0;
}
