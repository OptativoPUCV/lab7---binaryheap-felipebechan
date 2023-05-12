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
// listo
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

  while (i > 0 &&
         pq->heapArray[i].priority > pq->heapArray[(i - 1) / 2].priority) {
    heapElem vtemp = pq->heapArray[i];
    pq->heapArray[i] = pq->heapArray[(i - 1) / 2];
    pq->heapArray[(i - 1) / 2] = vtemp;
    i = (i - 1) / 2;
  }
  pq->size++;
}
// listo

void heap_pop(Heap *pq) {
  //check 0
    if (pq == NULL || pq->size == 0) {
        return;
    }
  // init padre hijo var
    int padre = 0;
    int hijo = 2*padre + 1;
 // reduc tamano heap y reempl raiz ult elem
    pq->size--;
    pq->heapArray[0] = pq->heapArray[pq->size];
  //while hj exist buscar prioridad
    while (hijo < pq->size) {
        if (hijo + 1 < pq->size && pq->heapArray[hijo + 1].priority > pq->heapArray[hijo].priority) {
            hijo++;
        }

        if (pq->heapArray[padre].priority >= pq->heapArray[hijo].priority) {
            break;
        }

        heapElem temp = pq->heapArray[padre];
        pq->heapArray[padre] = pq->heapArray[hijo];
        pq->heapArray[hijo] = temp;

        padre = hijo;
        hijo = 2*padre + 1;
    }
}
// listo

Heap *createHeap() { return NULL; }
