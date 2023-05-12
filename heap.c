#include "heap.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
  void *data;
  int priority;
} heapElem;

typedef struct Heap {
  heapElem *heapArray;
  int size;
  int capac;
} Heap;

void *heap_top(Heap *pq) {
  if (pq == NULL || pq->size == 0)
    return NULL;
  return pq->heapArray[0].data;
}

void heap_push(Heap *pq, void *data, int priority) {
  // check 0
  if (pq == NULL || pq->size == 0)
    return;

  if (pq->size == pq->capac) {
    int ncap = (2 * pq->capac) + 1;
    pq->heapArray = realloc(pq->heapArray, ncap * sizeof(heapElem));
    pq->capac = ncap;
  }
  int i = pq->size;
  pq->heapArray[i].data = data;
  pq->heapArray[i].priority = priority;

  while (i > 0 && pq->heapArray[i].priority > pq->heapArray[(i - 1) / 2].priority) {
    heapElem vtemp = pq->heapArray[i];
    pq->heapArray[i] = pq->heapArray[(i - 1) / 2];
    pq->heapArray[(i - 1) / 2] = vtemp;
    i = (i - 1) / 2;
  }
  pq->size++;
}
//listo

void heap_pop(Heap *pq) {}

Heap *createHeap() { return NULL; }
