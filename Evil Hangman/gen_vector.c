#include "gen_vector.h"
#include "generic.h"
#include <stdio.h>
#include <stdlib.h>


G_VECTOR g_vector_init_default(void(*assign)(Item* pLeft, Item Right), void(*destroy)(Item* pItem)){
  G_Vector *pVector;
  pVector = (G_Vector*)malloc(sizeof(G_Vector));
  if(pVector == NULL){
    printf("Error: Could not initialize pVector.\n");
  }
  pVector->capacity =1;
  pVector->size =0;
  pVector->data = (Item*)malloc(sizeof(Item)*pVector->capacity);
  if(pVector->data == NULL){
    printf("Error: Could not init space for pVector->data.\n");
    free(pVector);
    pVector = NULL;
  }
  for(int i=0; i< pVector->capacity; ++i){
    pVector->data[i] = NULL;
    pVector->assign = assign;
    pVector->destroy = destroy;
  }
  return pVector;
  }

//size & capacity
int g_vector_get_capacity(G_VECTOR hVector){
  G_Vector *pVector = (G_Vector*)hVector;
  int cap = pVector->capacity;
  return cap;    
}

int g_vector_get_size(G_VECTOR hVector){
  G_Vector *pVector = (G_Vector*)hVector;
  int size = pVector->size;
  return size;
}

Status g_vector_pushback(G_VECTOR hVector, Item itm){
  G_Vector* pVector = (G_Vector*)hVector;
  Item* tmp;
  int i=0;

  //allocate memory for vector if too small
  if(pVector->size >= pVector->capacity){
    tmp= (Item*)malloc(sizeof(Item)*2*pVector->capacity);
    if(tmp == NULL) return FAILURE;

    //copy data into tmp
    for(i=0; i<pVector->capacity; i++){
      tmp[i] = pVector->data[i];
  }
    pVector->capacity *=2;
    for(i=pVector->size; i<pVector->capacity; i++)
      tmp[i] = NULL;

    free(pVector->data);
    pVector->data= tmp;
  }
  //using assignment to place item into vector at last data index
  pVector->assign(&pVector->data[pVector->size], itm);
  pVector->size++;
  return SUCCESS; 
}

Status g_vector_popback(G_VECTOR hVector){
  G_Vector* pVector = (G_Vector*)hVector;

  if(pVector->size <=0)
    return FAILURE;

  pVector->size--;
  if(pVector->data[pVector->size] != NULL){
    pVector->destroy(&(pVector->data[pVector->size]));
  }
  return SUCCESS;
}

//vector empty, vector at & destroy
Item g_vector_at(G_VECTOR hVector, int index){
  G_Vector* pVector = (G_Vector*)hVector;

  if(index <0 || index>= pVector->size){
    return NULL;
  }
  return pVector->data[index];
}


Boolean g_vector_empty(G_VECTOR hVector){
  G_Vector* pVector = (G_Vector*)hVector;
  if(pVector->size >0)
    return FALSE;

  else
    return TRUE;
}

void g_vector_destroy(G_VECTOR *phVector){
  G_Vector* pVector = (G_Vector*)*phVector;
  for(int i=0; i<pVector->capacity; ++i){
    if(pVector->data[i] != NULL)
    pVector->destroy(&(pVector->data[i]));
  }
  free(pVector->data);
  free(pVector);
  *phVector=NULL;

}

