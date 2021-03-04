#ifndef GENERIC_H
#define GENERIC_H
#include "status.h"


typedef void* Item;
struct g_vector{
  int size;
  int capacity;
  Item *data;
  void (*assign)(Item *pLeft, Item Right);
  void (*destroy)(Item *pItem);
};
typedef struct g_vector G_Vector;


#endif
