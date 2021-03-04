#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "my_string.h"
#include <ctype.h>

struct my_string
{
  int size;
  int capacity;
  char* data;
};
typedef struct my_string My_String;


MY_STRING my_string_init_default(void){
  My_String* pMy_string = NULL;
  pMy_string = (My_String*)malloc(sizeof(My_String));

  if(pMy_string != NULL){
    pMy_string->capacity = 7;
    pMy_string->size = 0;
    pMy_string->data = (char*)malloc(sizeof(char)*(pMy_string->capacity));

    return (MY_STRING)pMy_string;
  }

  else
    {
    return NULL;
    }
}


MY_STRING my_string_init_c_string(const char* c_string){

  My_String* pMy_string = NULL;
  pMy_string = (My_String*)malloc(sizeof(My_String));

  int size = 0;
  int n = 0;

  while(c_string[size] != '\0'){  //determine size of c_string
    size++;
  }

  if(pMy_string != NULL){ //if pMy_string has been allocated, assign size, data
    pMy_string->size = (size);
    pMy_string->capacity = (pMy_string->size) + 1;
    pMy_string->data = malloc(sizeof(char)*pMy_string->capacity);

    
    while(c_string[n] != '\0'){ //assign pMy_string values of given cstring
      pMy_string->data[n] = c_string[n];
      n++;
      } 
    return (MY_STRING)pMy_string;
  }

  else {
    return NULL;
        }
}


int my_string_get_capacity(MY_STRING hMy_string){
  int capacity;
  My_String * pMy_string = (My_String*)hMy_string;

  capacity = pMy_string->capacity;

  
  return capacity;
}

int my_string_get_size(MY_STRING hMy_string){
  int size = 0;
  My_String * pMy_string = (My_String*)hMy_string;

  size = pMy_string->size;
  
  return size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
  My_String * pLeft_string = (My_String*)hLeft_string;

  My_String * pRight_string = (My_String*)hRight_string;
  int i = 0;
  int minLength = 0;

    
  //defining minLength
   if(pLeft_string->size < pRight_string->size){
    minLength = pLeft_string->size; 
   }
   else {
     minLength = pRight_string->size;  
  }
  
   for(i=0; i< minLength; i++){
     if(pLeft_string->data[i] > pRight_string->data[i]){
       return 1;
     }
     if(pLeft_string->data[i] < pRight_string->data[i])
       return -1;
   }

   return 0;   
 }

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){
  My_String* pMy_string = NULL;
  pMy_string = (My_String*)hMy_string;
  char ch;
  char* tmp;
  int retfScan;
  int n;
  
  //reading first char from file
  retfScan = fscanf(fp, " %c", &ch);
 
  if(retfScan <= 0 || retfScan == EOF){
    return FAILURE;
  }
  while(isspace(ch)){
       retfScan = fscanf(fp, "%c", &ch);
    }

       pMy_string->size = 0;

    //iterates as long as there are unread chars and char being scanned isnt a space
    while(retfScan >= 0 && !isspace(ch)){ 
    pMy_string->data[pMy_string->size] = ch;
    pMy_string->size++;
    retfScan = fscanf(fp, "%c", &ch);
    
    if(pMy_string->size >= pMy_string->capacity){
      tmp = (char*)malloc(sizeof(char)*pMy_string->capacity*2);
      pMy_string->capacity = (pMy_string->capacity)*2;
      if(tmp == NULL){
	printf("Memory allocation failed");
	exit(1);
      }
      
      for(n=0; n<pMy_string->size-1; n++){
	tmp[n] = pMy_string->data[n];
      }
      free(pMy_string->data);
      pMy_string->data = tmp;
    }
  }
  if(retfScan != EOF){
    ungetc(ch, fp);
  }

  return SUCCESS;
}


Status my_string_insertion(MY_STRING hMy_string, FILE* fp){
  My_String* pMy_string = (My_String*)hMy_string;
  int n = 0;
  if(pMy_string != 0){

    for(n=0; n < pMy_string->size; n++){
      fputc(pMy_string->data[n], fp);
    }

    return SUCCESS;
  }
  else { return FAILURE; }
}

//void my_string_destroy(MY_STRING* phMy_string){ //definition for lab 5
void my_string_destroy(Item* pItem){   //definition for lab 6
  My_String* pMy_string = (My_String*)*pItem;  //assignment for lab 6
 
   free(pMy_string->data);
  free(pMy_string);

  
  *pItem = NULL;

}


Status my_string_pop_back(MY_STRING hMy_string){
  My_String* pMy_string = (My_String*)hMy_string;

  if(pMy_string->size > 0){
    pMy_string->size--;
    return SUCCESS;
  }
  else {
    return FAILURE;
  }
}

Status my_string_push_back(MY_STRING hMy_string, char item){
  My_String* pMy_string = (My_String*)hMy_string;
  char* tmp;
  
  if(pMy_string->size >= pMy_string->capacity){
    tmp = (char*)malloc(sizeof(char)*2*pMy_string->capacity);
    if(tmp == NULL){
      return FAILURE;
    }
    for(int i=0; i< pMy_string->size; i++){
      tmp[i] = pMy_string->data[i];
    }
    free(pMy_string->data);
    pMy_string->data =  tmp;
    pMy_string->capacity = (pMy_string->capacity *2);
  }
  
  pMy_string->data[pMy_string->size] = item;
  pMy_string->size++;
  return SUCCESS;  
}

char* my_string_at(MY_STRING hMy_string, int index){
  My_String* pMy_string = (My_String*)hMy_string;

  if(index >= pMy_string->size || index < 0){
    return NULL;
  }
  return &(pMy_string->data[index]);
 }


char* my_string_c_str(MY_STRING hMy_string){
  My_String* pMy_string = (My_String*)hMy_string;

  pMy_string->data[pMy_string->size] = '\0';
  pMy_string->capacity = pMy_string->size +1;
  
  return pMy_string->data;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){
  My_String* pResult = (My_String*)hResult;
  My_String* pAppend = (My_String*)hAppend;

  char* tmp = NULL;
  //return failure if either string is empty  
  if(pAppend->size == 0 || pResult->size == 0){
    return FAILURE;
  }

  //if pResult doesnt have enough capacity for both strings, allocate mem
  if(pResult->capacity < (pResult->size + pAppend->size)){
    tmp = (char*)malloc(sizeof(char)* (pResult->size +pAppend->size)*2);

    if(tmp == NULL){
      return FAILURE;
    }

    //copy pResult to new arr 
    for(int i=0; i<= pResult->size; i++){
      tmp[i] = pResult->data[i];
    }
    free(pResult->data);
    pResult->data = tmp;
    pResult->capacity = (pResult->size + pAppend->size);
  }
  //combine both strings + add null at end
  for(int i=0; i<= pAppend->size; i++){
    pResult->data[pResult->size+i] = pAppend->data[i];
  }
  pResult->size = (pResult->size + pAppend->size);// +1);
  pResult->data[pResult->size] = '\0';

  return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string){
  My_String* pMy_string = (My_String*)hMy_string;

  if(pMy_string->size == 0){ //if string is empty, return 1
    return TRUE;
  }
  else {
    return FALSE;
  }
}

void my_string_assignment(Item* pLeft, Item Right){

 My_String *pLeftStr = (My_String*) *pLeft;
 My_String *pRightStr = (My_String*) Right;

 char *tmp;
 int n = 0;

 tmp = my_string_c_str((MY_STRING)Right);
 
 int rightSize =  my_string_get_size(pRightStr);
 
 //if left string is empty/NULL, it is initialized as a copy of right string
 if(pLeftStr == NULL){
   pLeftStr = my_string_init_c_string(tmp);
 }

 else{
   pLeftStr->size = 0;
   for(n=0; n< rightSize+1; n++){
   my_string_push_back(pLeftStr, pRightStr->data[n]);
   }
 }
 *pLeft = pLeftStr;

}


