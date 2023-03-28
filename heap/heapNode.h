
#include <stdio.h>
#include <stdlib.h>

struct HeapNode
{
  /* Requeridos */
  int weight;
};

typedef struct HeapNode HeapNode;

HeapNode *heapNodeInit(int weight)
{
  HeapNode *foo = malloc(sizeof(HeapNode));

  if (foo == NULL)
  {
    /* Cannot allocate memory */
    printf("heapNodeInit: No se puede reservar memoria\n");
    exit(EXIT_FAILURE);
  }

  foo->weight = weight;

  return foo;
}