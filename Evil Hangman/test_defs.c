//TEST_DEFS.C: implementation for TEST functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"
#include "unit_test.h"
#include "gen_vector.h"
#include "generic.h"
#include "gen_vector.c"

 // TEST for init function: to see if string is initialized correctly &
  // returns nonNull 
Status test_1_snazar_init_default_returns_nonNULL(char* buffer, int length){
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  if(hString == NULL){
     my_string_destroy((Item*)&hString);
    //my_string_destroy(&hString);
    strncpy(buffer, "test_1_snazar_init_default_returns_nonNULL\n""\tDid not get expected result from my_string_init_default_returns_nonNULL\n", length);
    return FAILURE;
  }
  else{
    my_string_destroy(&hString);
    strncpy(buffer, "test_1_snazar_init_default_returns_nonNULL\n", length);
    return SUCCESS;
  }
}

//Test to make sure newly initialized string has size = 0
Status test_2_snazar_get_size_on_init_default_returns_0(char* buffer, int length){
  Status status;
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  if( my_string_get_size(hString) != 0){
    status = FAILURE;
    printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
    strncpy(buffer, "test_2_snazar_get_size_on_init_default_returns_0\n" "\tDid not receive 0 from get_size_after_init_default\n", length);
  }
  else {
    status = SUCCESS;
   strncpy(buffer, "test_2_snazar_get_size_on_init_default_returns_0\n", length);
  }

  my_string_destroy((Item*)&hString);
  //my_string_destroy(&hString);
  return  status;
}

// Test to make verify destroy function 
Status test_3_snazar_destroy_object(char* buffer, int length){
  Status status;
  MY_STRING hString = NULL;

  hString = my_string_init_default();

   my_string_destroy((Item*)&hString);
  //my_string_destroy(&hString);

  if(hString == NULL){
    status = SUCCESS;
    strncpy(buffer, "test_3_snazar_destroy_object returned NULL", length);
  }
  else {
    status = FAILURE;
    strncpy(buffer, "test_3_snazar_destroy_object""\tDid not get expected result \from test_3_snazar_destroy_object\n", length);
  }
  return status;
}

 // Test to make verify that my_string_init_c_string assigns a string to a
 // string object and string size is not zero 
Status test_4_snazar_get_size_on_init_c_str_returns_non_0(char* buffer, int length){
  Status status;
  MY_STRING hString;
  hString = my_string_init_c_string("Test string for Test function #4");

  if(my_string_get_size(hString) !=  0){
    status = SUCCESS;
    strncpy(buffer, "test_4_snazar_get_size_on_init_c_str_returns_non_0\n", length);
  }

  else if(my_string_get_size(hString)== 0){
    status = FAILURE;
    printf("Expected a size of non 0 but got %d\n", my_string_get_size(hString));
    strncpy(buffer, "test_4_snazar_get_size_on_init_c_str_returns_non_0\n""\tDid \not receive non 0 from get_size after c_string_init\n", length);
  }
  my_string_destroy((Item*)&hString);
  //my_string_destroy(&hString);
  return status;
}

// Testing my_string_get_size function
Status test_5_snazar_string_get_size(char* buffer, int length){
  Status status;
  MY_STRING hString = NULL;
  int size = 0;
  hString = my_string_init_c_string("Test string for test 5");
  size = my_string_get_size(hString);

  if((my_string_get_size(hString) > size) || my_string_get_size(hString) < 0){
    status = FAILURE;
    printf("Expected size of %d, but got %d\n", size, my_string_get_size(hString));
    strncpy(buffer, "test_5_snazar_string_get_size\n""\tWrong size was returned using using test_5_snazar_string_get_size\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_5_snazar_string_get_size\n", length);
  }

   my_string_destroy((Item*)&hString);
  //my_string_destroy(&hString);
  return status;
}

// Testing my_string_get_capacity function
Status test_6_snazar_string_get_capacity(char* buffer, int length){
  Status status;
  MY_STRING hString;
  int capacity = 0;
  hString = my_string_init_c_string("Test string for test 6");

  capacity = my_string_get_capacity(hString);

  if((my_string_get_capacity(hString) > capacity) || my_string_get_capacity(hString) < 0){
    status = FAILURE;
    printf("Expected capacity of %d, but got %d\n", capacity, my_string_get_capacity(hString));
    strncpy(buffer, "test_6_snazar_string_get_capacity\n""\tWrong capacity was returned using test_6_snazar_get_capacity\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_6_snazar_string_get_capacity\n", length);
  }

   my_string_destroy((Item*)&hString);
  //my_string_destroy(&hString);
  return status;
}

// Testing my_string_pushback function
Status test_7_snazar_pushback(char* buffer, int length){
  Status status;
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  my_string_push_back(hString, 'a');
  my_string_push_back(hString, 'b');
  my_string_push_back(hString, 'c');

  if((my_string_get_size(hString) <= 0) || (my_string_get_size(hString) > 3))
    {
      status = FAILURE;
      printf("Failure: Expected string size after pushback to be 3, but got %d\\n", my_string_get_size(hString));
      strncpy(buffer, "test_7_snazar_pushback\n""\tPushback was not completed using test_7_snazar_pushback\n", length);
    }

  else{
    status = SUCCESS;
    strncpy(buffer, "test_7_snazar_pushback\n", length);
  }

  my_string_destroy((Item*)&hString);
  //my_string_destroy(&hString);
  return status;
}

// Testing popback functionality
Status test_8_snazar_popback(char* buffer, int length){
  Status status;
  MY_STRING hString = NULL;
  int size = 0;

  hString = my_string_init_c_string("Test string for test 8");
  size = my_string_get_size(hString);

  for(int i=0; i< size; i++){
    my_string_pop_back(hString);
  }

  if(my_string_get_size(hString) == 0){
    status = SUCCESS;
    strncpy(buffer, "test_8_snazar_popback\n", length);
  }

  else{
    status = FAILURE;
    printf("Expected string size 0 after popback but got %d\n", my_string_get_size(hString));
    strncpy(buffer, "test_8_snazar_popback\n""\tUnsuccessful popback using fu\
nction test_8_snazar\n", length);
  }
   my_string_destroy((Item*)&hString);
  //my_string_destroy(&hString);
  return status;
}

// Testing concat functionality
Status test_9_snazar_concat(char* buffer, int length){
  Status status;
  MY_STRING hLeftStr = NULL;
  MY_STRING hRightStr = NULL;
  int sizeLeft = 0;
  int sizeRight = 0;
  int sizeResult = 0;
  hLeftStr = my_string_init_c_string("Hello");
  hRightStr = my_string_init_c_string("World");

  sizeLeft = my_string_get_size(hLeftStr);
  sizeRight = my_string_get_size(hRightStr);

  my_string_concat(hLeftStr, hRightStr);

  sizeResult = my_string_get_size(hLeftStr);

  if((sizeResult < (sizeLeft + sizeRight)) || (sizeResult > (sizeLeft+ sizeRight))){
    status = FAILURE;
    printf("Expected a resulting string size of %d after concat function but \
got %d\n", (sizeLeft + sizeRight), sizeResult);
    strncpy(buffer, "test_9_snazar_concat\n""\tUnsuccessful concat performed using test_9_snazar_concat\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_9_snazar_concat\n", length);
  }

   my_string_destroy((Item*)&hLeftStr);
   my_string_destroy((Item*)&hRightStr);
  //my_string_destroy(&hLeftStr);
  //my_string_destroy(&hRightStr);
  return status;
}

// Testing my_string_empty function //
Status test_10_snazar_string_empty_returns_0(char* buffer, int length){
  Status status;
  MY_STRING hString = NULL;
  int is_empty;

  hString = my_string_init_c_string("Test String for test 10.");
  is_empty = my_string_empty(hString);

  if(is_empty != 0){
    status = FAILURE;
    printf("Expected 0 but got %d\n", is_empty);
    strncpy(buffer, "test_10_snazar_string_empty_returns_non_0\n""\tDid not receive 0 from test_10_snazar\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_10_snazar_string_empty_returns_0\n", length);
  }

  my_string_destroy((Item*)&hString);
  //my_string_destroy(&hString);
  return status;
}

// testing my_string_at function with invalid negative index
Status test_11_snazar_string_at_returnsNULL(char* buffer, int length){
  Status status;
  MY_STRING hString = NULL;
  char* atIndex;
  hString = my_string_init_c_string("Test String for test 11");

  atIndex = my_string_at(hString, -1);

  if(atIndex == NULL){
    status = SUCCESS;

    strncpy(buffer, "test_11_snazar_string_at_returnsNULL\n", length);
  }
  else{
    status = FAILURE;
    strncpy(buffer, "test_11_snazar_string_at_returnsNULL\n""\tDid not get expected NULL value from test_11_snazar_string_at_returnsNULL\n", length);
  }

   my_string_destroy((Item*)&hString);
  // my_string_destroy(&hString);
  return status;

}


// Testing string_at function at an index greater than string size 
Status test_12_snazar_string_at_invalid_large_index(char* buffer, int length){
  Status status;
  MY_STRING hString = NULL;
  hString = my_string_init_c_string("Test String for test 12");
  int stringSize = my_string_get_size(hString);

  char* atIndex = my_string_at(hString, (stringSize+2));

  if(atIndex == NULL){
    status = SUCCESS;
    strncpy(buffer, "test_12_snazar_string_at_invalid_large_index\n", length);
  }
  else{
    status = FAILURE;
    strncpy(buffer, "test_12_snazar_string_at_invalid_large_index\n""\tDid not ge\
t expected NULL value from test_12_snazar\n", length);
  }

  my_string_destroy((Item*)&hString);
  //my_string_destroy(&hString);
  return status;

}

// Testing proper file creation to be used for testing extract function
Status test_13_snazar_create_write_file(char* buffer, int length){
  Status status;
  FILE *fp = fopen("test_file.txt", "w");
  if(fp == NULL){
    status = FAILURE;
    printf("Failure:  unable to create file.\n");
    strncpy(buffer, "test_13_snazar_create_write_file\n""\tDid not create file using test_13_snazar_create_write_file\n", length);
  }
  else{
    status = SUCCESS;
    fprintf(fp, "Test file text");
    fclose(fp);
    strncpy(buffer, "test_13_snazar_create_write_file\n", length);
  }
  return status;
}

// Testing file read 
Status test_14_snazar_extraction_read_file(char* buffer, int length){
  Status status;
  FILE *fp;
  MY_STRING expectedExtraction = my_string_init_c_string("file");
  MY_STRING extractedWord = my_string_init_default();
  //content of test_file.txt = "test file text"
  fp = fopen("test_file.txt", "r");

  if(fp != NULL){
    my_string_extraction(extractedWord, fp);
    my_string_extraction(extractedWord, fp);
    
    if(my_string_compare(expectedExtraction, extractedWord) == 0){
      strncpy(buffer, "test_14_snazar_extraction_read_file\n", length);
      status = SUCCESS;
    }
    else{
      printf("Failure: Did not extract expected word in test_14_snazar\n");
      strncpy(buffer, "test_14_snazar_extraction_read_file\n""\tDid not get expected result from test_14_snazar_extraction_read_file\n", length);
      status = FAILURE;
    }
   }
  else{
    printf("Failure: Did not extract expected word in test_14\n");
    strncpy(buffer, "test_14_snazar_extraction_read_file\n""\tDid not get expected result from test_14_snazar_extraction_read_file\n", length);
    status = FAILURE;
  }

 fclose(fp);
 
 my_string_destroy((Item*)&expectedExtraction);
 my_string_destroy((Item*)&extractedWord);
 //my_string_destroy(&expectedExtraction);
 //my_string_destroy(&extractedWord);

return status;
}


// Testing proper file deletion after extraction test
Status test_15_snazar_delete_file(char* buffer, int length){
  Status status;
  //should == 0 if file is deleted, ==1 if FAILURE
  if((remove("test_file.txt")) == 1){
    status = FAILURE;
    printf("Failure: Unable to delete test_file.txt in test_15_snazar.\n");
    strncpy(buffer, "test_15_snazar_delete_file\n""\tDid not get expected result from test_15_snazar_delete_file\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_15_snazar_delete_file\n", length);
  }
  return status;
}

// Testing compare function with 2 identical strings, expecting 0 
Status test_16_snazar_compare_identical(char* buffer, int length){
  Status status;
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int compareVal = 0;
  hLeft = my_string_init_c_string("Test");
  hRight = my_string_init_c_string("Test");

  compareVal = my_string_compare(hLeft, hRight);

  if(compareVal <0 || compareVal > 0){
    status = FAILURE;
    printf("Failure: expected 0 for identical string compare, but got %d\n", compareVal);
    strncpy(buffer, "test_16_snazar_compare_identical\n""\tDid not get expected result from test_16_snazar_compare_identical\n", length);
  }

  else {
    status = SUCCESS;
    strncpy(buffer, "test_16_snazar_compare_identical\n", length);
  }

  my_string_destroy((Item*)&hLeft);
  my_string_destroy((Item*)&hRight);
  //my_string_destroy(&hLeft);
  //my_string_destroy(&hRight);
  return status;
}

//return 1 if L is bigger, -1 if L is smaller
Status test_17_snazar_compare_diff_zebra_Apple(char* buffer, int length){
  Status status;
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int compVal;
  int correctVal = 1;

  hLeft = my_string_init_c_string("zebra");
  hRight = my_string_init_c_string("Apple");

  compVal = my_string_compare(hLeft, hRight);

  if(compVal != correctVal){
    status = FAILURE;
    printf("Failure: expected 1 for string compare but got %d\n", compVal);
    strncpy(buffer, "test_17_snazar_compare_diff_zebra_Apple""\tDid not get expected result from test_17_snazar_compare_diff_zebra_Apple\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_17_snazar_compare_diff_zebra_Apple\n", length);
  }
  my_string_destroy((Item*)&hRight);
  my_string_destroy((Item*)&hLeft);
  
  //my_string_destroy(&hLeft);
  //my_string_destroy(&hRight);

  return status;

}

Status test_18_snazar_compare_diff_apple_Zebra(char* buffer, int length){
  Status status;
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int compVal;
  int correctVal = 1;

  hLeft = my_string_init_c_string("apple");
  hRight = my_string_init_c_string("Zebra");

  compVal = my_string_compare(hLeft, hRight);

  if(compVal != correctVal){
    status = FAILURE;
    printf("Failure: expected 1 from string compare but got %d\n", compVal);
    strncpy(buffer, "test_18_snazar_compare_diff_apple_Zebra\n""\tDid not get expected result from test_18_snazar_compare_diff_apple_Zebra\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_18_snazar_compare_diff_apple_Zebra\n", length);
  }

  my_string_destroy((Item*)&hLeft);
  my_string_destroy((Item*)&hRight); //lab6
  
  // my_string_destroy(&hLeft);
  // my_string_destroy(&hRight);
  return status;
}

Status test_19_snazar_compare_diff_str_right_long(char* buffer, int length){
  Status status;
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int compVal;
  int correctVal = -1;

  hLeft = my_string_init_c_string("apple");
  hRight = my_string_init_c_string("zebras");
  compVal = my_string_compare(hLeft, hRight);

  if(compVal != correctVal){
    status = FAILURE;
    printf("Failure: expected -1 from string compare but got %d\n", compVal);
    strncpy(buffer, "test_19_snazar_compare_diff_str_right_long\n""\tDid not get expected", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_19_snazar_compare_diff_str_right_long\n", length);
  }
  my_string_destroy((Item*)&hLeft);
  my_string_destroy((Item*)&hRight); //lab 6^ 
  
  //my_string_destroy(&hLeft);
  //my_string_destroy(&hRight);
  return status;
}

Status test_20_snazar_compare_diff_str_left_long(char* buffer, int length){
  Status status;
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int compVal;
  int correctVal = 1;

  hLeft = my_string_init_c_string("zebra");
  hRight = my_string_init_c_string("apples");

  compVal = my_string_compare(hLeft, hRight);

  if(compVal != correctVal){
    status = FAILURE;
    printf("Failure: expected non-negative from compare but got %d\n", compVal);
    strncpy(buffer, "test_20_snazar_diff_str_left_long\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_20_snazar_compare_diff_str_left_long\n", length);
  }

   my_string_destroy((Item*)&hLeft); //LAB6
   my_string_destroy((Item*)&hRight); //LAB6

   //my_string_destroy(&hLeft);
  //my_string_destroy(&hRight);
  return status;
}

Status test_21_snazar_compare_identical_A_Z(char*buffer, int length){
  Status status;
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int compVal;
  hLeft = my_string_init_c_string("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
  hRight = my_string_init_c_string("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");

  compVal = my_string_compare(hLeft, hRight);
  if(compVal > 0 || compVal < 0){
    status = FAILURE;
    printf("Failure: Expected 0 from compare but got %d\n", compVal);
    strncpy(buffer,"test_21_snazar_compare_identical_A_Z\n" "\tFailure: did not get expected result from test_21_snazar_compare_identical_A_Z\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_21_snazar_compare_identical_A_Z\n", length);
  }

   my_string_destroy((Item*)&hLeft); //LAB6
   my_string_destroy((Item*)&hRight); //LAB6
  //  my_string_destroy(&hLeft);
  //my_string_destroy(&hRight);

  return status;
}

Status test_22_snazar_compare_identical_a_z(char*buffer, int length){
  Status status;
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int compVal;

  hLeft = my_string_init_c_string("a b c d e f g h i j k l m n o p q r s t u v w x y z");
  hRight = my_string_init_c_string("a b c d e f g h i j k l m n o p q r s t u v w x y z ");

  compVal = my_string_compare(hLeft, hRight);

  if(compVal > 0 || compVal < 0){
    status = FAILURE;
    printf("Failure: Expected 0 from compare but got %d\n", compVal);
    strncpy(buffer, "test_22_snazar_identical_a_z\n""\tDid not get expected result from test_22_snazar_identical_a_z\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_22_snazar_compare_identical_a_z\n", length);
  }

   my_string_destroy((Item*)&hRight); //LAB6
   my_string_destroy((Item*)&hLeft); //LAB6
  
   //my_string_destroy(&hLeft);
   //my_string_destroy(&hRight);
  return status;
}

Status test_23_snazar_compare_identical_Z_A(char*buffer, int lentgth){
  Status status;
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int compVal = 0;

  hLeft = my_string_init_c_string("Z Y X W V U T S R Q P O N M L K J I H G F E D C B A");
  hRight = my_string_init_c_string("Z Y X W V U T S R Q P O N M L K J I H G F E D C B A");

  compVal = my_string_compare(hLeft, hRight);

  if(compVal >0 || compVal < 0){
    status = FAILURE;
    printf("Failure: Expected 0 from comparison but got %d\n", compVal);
    strncpy(buffer, "test_23_snazar_compare_identical_Z_A\n""\tDid not get correct result from test_23_snazar_compare_identical_Z_A\n", lentgth);

  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_23_snazar_compare_identical_Z_A\n", lentgth);
  }

  
   my_string_destroy((Item*)&hLeft); //LAB6
   my_string_destroy((Item*)&hRight); //LAB6
  
  //my_string_destroy(&hLeft);
  //my_string_destroy(&hRight);

  return status;
}


Status test_24_snazar_compare_identical_z_a(char*buffer, int length){
  Status status;
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int compVal;

  hLeft = my_string_init_c_string("z y x w v u t s r q p o n m l k j i h g f e d c b a");
  hRight = my_string_init_c_string("z y x w v u t s r q p o n m l k j i h g f e d c b a");

  compVal = my_string_compare(hLeft, hRight);
  if(compVal > 0 || compVal < 0){
    status = FAILURE;
    printf("Failure: Expected 0 from comparison but got %d\n", compVal);
    strncpy(buffer, "test_24_snazar_compare_identical_z_a\n""\tDid not get expected result from test_24_snazar_compareidentical_z_a\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_24_snazar_compare_identical_z_a\n", length);
  }

   my_string_destroy((Item*)&hLeft); //LAB6
   my_string_destroy((Item*)&hRight); //LAB6
  
   //my_string_destroy(&hLeft);
   //my_string_destroy(&hRight);

  return status;
}

Status test_25_snazar_str_empty_returns_1(char* buffer, int length){
  Status status;
  MY_STRING hString = NULL;
  hString = my_string_init_default();
  int isEmpty;

  isEmpty = my_string_empty(hString);
  if(isEmpty != 1){
    status = FAILURE;
    printf("Failure: Expected 1 from is empty test but got %d\n", isEmpty);
    strncpy(buffer, "test_25_snazar_str_empty_returns_1\n""\tDid not get expected result from test_25_snazar_str_empty_returns_1\n", length);
  }
  else{
    status = SUCCESS;
    strncpy(buffer, "test_25_snazar_str_empty_returns_1\n", length);
  }

  my_string_destroy((Item*)&hString); //LAB6
  
  //my_string_destroy(&hString);
  return status;
}

// LAB6
Status lab6_checkpoint(char* buffer, int length){
  MY_STRING hMy_string[100];
  Status status;

   for(int i=0; i< 100; i++){
    hMy_string[i] = NULL;
  }
  hMy_string[0] = my_string_init_c_string("COPY ME!");

  for(int i=0; i<100; i++){
    my_string_assignment(&hMy_string[i], hMy_string[0]);
  }
  for(int i=0; i<100; i++){
    my_string_insertion(hMy_string[i], stdout);
    printf("\n");
    my_string_destroy((Item*)&hMy_string[i]);
  }
  status = SUCCESS;

  strncpy(buffer, "lab6_checkpoint successfully created 100 copied strings\n", length);

  return status;  
}

Status lab7_checkpoint1(char* buffer, int length){
  Status status;
  FILE *fp;
  G_VECTOR arr[30];
  MY_STRING hString = my_string_init_default();
  
  //initializing array elements generic vectors
  for(int i=0; i<30; ++i){
    arr[i] = g_vector_init_default(my_string_assignment, my_string_destroy);

    if(arr[i] == NULL){
      status = FAILURE;
      printf("Error: Could not allocate space for array g_vectors\n");
      return status;
    }
}
  fp=fopen("dictionary.txt", "r");

  if(fp == NULL){
    printf("Error: Could not open dictionary.txt\n");
    status = FAILURE;
    return status;
  }
  //ectracting words that are less than 29 chars long from dictionary.txt
  //using pushback to assign word into array
  while((my_string_extraction(hString, fp) == 1)){
    if(my_string_get_size(hString)< 29){
       int size = my_string_get_size(hString);
       g_vector_pushback(arr[size], hString);
    }
  }

     for(int i=0; i<30; ++i){
       printf("There are %d words with %d characters\n", g_vector_get_size(arr[i]), i);
       }
     
   for(int i=0; i<30; ++i){
   g_vector_destroy(&(arr[i]));
   }

  fclose(fp);
  my_string_destroy(&hString);
  status = SUCCESS;
  return status; 
}
