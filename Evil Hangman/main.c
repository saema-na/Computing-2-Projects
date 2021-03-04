#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
//#include "status.h"
#include <ctype.h>

int main(int argc, char* argv[]) {

  /*    //LAB 3 MAIN DRIVER
  MY_STRING hMy_string = NULL;   
  FILE* fp;
  hMy_string = my_string_init_default();
  fp = fopen("dictionary.txt", "r");
  while(my_string_extraction(hMy_string, fp)){
    // for lab3 checkpoint 2:
    if(my_string_get_size(hMy_string) == 5){
    my_string_insertion(hMy_string, stdout);
        printf("\n");
      }
    //   printf("\n");  
      if(fgetc(fp)==' '){
      printf("Found a space after the string.\n");
	} }
   my_string_destroy(&hMy_string);
  fclose(fp);
  return 0;
} */
  //  char item = 'z';


  MY_STRING hLeft_string = NULL;
  hLeft_string = my_string_init_c_string("abc");

  /*  char item = 'z';
  printf("Status of string_push function: %d\n", my_string_push_back(hLeft_string, item));
  my_string_insertion(hLeft_string, stdout);
  printf("\n");


  
   printf("\nStatus of string_pop function: %d\n", my_string_pop_back(hLeft_string));
   my_string_insertion(hLeft_string, stdout);
   printf("\n\n");


   
   char *charPtr = my_string_at(hLeft_string, 1);
   printf("String 'abc' @ index 1 using string_at function: %c\n\n", *charPtr);
   

   
   char* charPtr2 = my_string_c_str(hLeft_string);
   printf("my string c string: %c\n\n", *charPtr2);

  */

   
   MY_STRING hLeft = my_string_init_c_string("Test");
   MY_STRING hRight = my_string_init_c_string("Testing Testing");
   //  printf("Status for string append: %d", my_string_concat(hResult, hAppend));
   //   my_string_insertion(hResult, stdout);
   // printf("\n\n");

   printf("\n\nCOMPARE VALUE right longer: %d\n\n", my_string_compare(hLeft, hRight));

   
   printf("String empty function with non-empty string: %d\n", my_string_empty(hLeft_string));
   

   my_string_destroy(&hLeft_string);
   my_string_destroy(&hResult);
   my_string_destroy(&hAppend);
    
  return 0;
}

