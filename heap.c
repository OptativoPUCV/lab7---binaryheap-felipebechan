#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void *heap_top(Heap *pq) {
  if (pq == NULL || pq->size == 0)
    return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap *pq, void *data, int priority) {
  //check 0
  if (pq == NULL || pq->size == 0)
    return;
  //check lleno
  if (pq->size == pq->capac) 
  {
    int ncap = (2 * pq->capac) + 1;
    pq->heapArray = realloc(pq->heapArray, ncap * sizeof(heapElem));
    pq->capac = ncap;
  }

}



void heap_pop(Heap* pq){

}

Heap* createHeap(){

   return NULL;
}
