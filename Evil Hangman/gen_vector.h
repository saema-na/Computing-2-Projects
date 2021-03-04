#ifndef gen_vector_h
#define gen_vector_h
#include "generic.h"
#include <stdio.h>
#include <stdlib.h>
//#include "status.h"
typedef void* G_VECTOR;

//init
G_VECTOR g_vector_init_default(void(*assign)(Item* pLeft, Item Right), void(*destroy)(Item* pItem));

//size & capacity
int g_vector_get_capacity(G_VECTOR hVector);
			  

int g_vector_get_size(G_VECTOR hVector);

//pushback & popback
Status g_vector_pushback(G_VECTOR hVector, Item);

Status g_vector_popback(G_VECTOR hVector);

//vector empty & vector at & destroy
Item g_vector_at(G_VECTOR hVector, int);

Boolean g_vector_empty(G_VECTOR hVector);

void g_vector_destroy(G_VECTOR *phVector);

#endif
