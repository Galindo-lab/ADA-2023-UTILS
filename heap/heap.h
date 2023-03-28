
// jonathan del angel duarte Garcia
// Omar alejandro gaona gonzales

/**
 * AUTOR: Luis Eduardo Galindo Amaya                           FECHA: 23-3-2023
 *
 * DESCRIPCIÓN:
 */

#include "heapNode.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Representa un heap en con memoria dinamica
 * @param nodes puntero a los nodos
 * @param nodeSize tamaño de cada nodo
 * @param maxSize numero maximo de nodos posibles
 * @param size numero de nodos usados
 */
typedef struct
{
  HeapNode *nodes;
  int maxSize;
  int size;
} Heap;

/**
 * Obtiene la cantidad de elementos utilizados en el heap
 * @param heap puntero al heap
 */
int heapSize(Heap *heap)
{
  return heap->size;
}

/**
 * Numero maximo de nodos que puede tener el heap
 * @param heap puntero al heap
 */
int heapMaxSize(Heap *heap)
{
  return heap->maxSize;
}

/**
 * Retorna si no se ha usado ninguno de los nodos en el grafo
 * @param heap puntero al heap
 */
char heapEmpty(Heap *heap)
{
  return heap->nodes == NULL;
}

void heapInit(Heap *heap, int heapSize)
{
  heap->nodes = malloc(sizeof(HeapNode) * heapSize);

  if (heap->nodes == NULL)
  {
    printf("heapInit: Error al reservar memoria\n");
    exit(EXIT_FAILURE);
  }

  heap->maxSize = heapSize;
  heap->size = 0;
}

HeapNode *heapGetNode(Heap *heap, int position)
{
  if (heapEmpty(heap))
  {
    printf("heapGetNode: heap vacio\n");
    exit(EXIT_FAILURE);
  }

  if (position >= heap->maxSize)
  {
    printf("heapGetNode: posicion invalida\n");
    exit(EXIT_FAILURE);
  }

  return &heap->nodes[position];
}

HeapNode *heapParentNode(Heap *heap, int position)
{

  int foo = (position - 1) / 2;

  if (foo == -1)
  {
    printf("heapParentNode: posicion invalida\n");
    exit(EXIT_FAILURE);
  }

  if (foo >= heap->maxSize)
  {
    printf("heapParentNode: Out of range\n");
    exit(EXIT_FAILURE);
  }

  return &heap->nodes[foo];
}

void heapDisplay(Heap *heap)
{
  printf("\n-*-\n");
  for (int i = 0; i < heap->size; i++)
  {
    printf("%d ", heap->nodes[i].weight);
  }
  printf("\n-*-\n");
}

void heapInsert(Heap *heap, HeapNode *node)
{
  if (heap->size == 0)
  {
    /* si el heap esta vacio */
    heap->nodes[0] = *node;
    heap->size++;
    return;
  }

  /* insertar el nodo al final */
  heap->nodes[heap->size] = *node;
  int heapSize = heap->size;
  heap->size++;

  while (1)
  {

    int parentWeight = heapParentNode(heap, heapSize)->weight;
    int nodeWeight = heapGetNode(heap, heapSize)->weight;

    if (parentWeight <= nodeWeight)
    {
      break;
    }
    else
    {
      /* cambiar el padre por el hijo */
      HeapNode miss = heap->nodes[heapSize];
      int bar = (heapSize - 1) / 2;

      heap->nodes[heapSize] = heap->nodes[bar];
      heap->nodes[bar] = miss;

      heapSize = bar;
    }
  }
}
