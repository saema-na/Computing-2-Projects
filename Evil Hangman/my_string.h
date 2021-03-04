#ifndef my_string_h
#define my_string_h
#include "status.h"
#include "generic.h"


typedef void* MY_STRING;

/* initialize and dynamically allocate space for a MYSTRING object */
MY_STRING my_string_init_default(void);

/* assign string to a MYSTRING object  */
MY_STRING my_string_init_c_string(const char* c_string);

/* return capacity available for a string  */
int my_string_get_capacity(MY_STRING hMy_string);

/* return size of a string  */
int my_string_get_size(MY_STRING hMy_string);

/*- return -1 if right string is lexographically greater than left &
   vice versa 
   -lexographically greater = longer, or have letters that come later in alphbt
 */
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

/* extract word from a file  */
Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

/* adds string to file stream  */
Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

/* deletes/frees space of a MYSTRING object  */
//void my_string_destroy(MY_STRING* phMy_string);
//-----> replace with void my_string_destroy(Item *pItem);
void my_string_destroy(Item* pItem);

/* adds a character to the end of inputted hMy_string  */
Status my_string_push_back(MY_STRING hMy_string, char item);

/* removes last character of hMy_string  */
Status my_string_pop_back(MY_STRING hMy_string);

/* returns address of character located at given index  */
char* my_string_at(MY_STRING hMy_string, int index);

/* returns address of 1st element of string, for use as a c-string  */
char* my_string_c_str(MY_STRING hMy_string);

/* adds hAppend string to end of hResult string, combines both  */
Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);

/* return true if string is empty and vice versa  */
Boolean my_string_empty(MY_STRING hMy_string);

void my_string_assignment(Item* pLeft, Item Right);

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess);


#endif 
