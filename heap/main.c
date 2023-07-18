
#include "heap.h"
#include <stdio.h>

int main() {
  Heap a;
  heapInit(&a, 10);


  /* heapInsert(&a,heapNodeInit(1)); */
  /* heapInsert(&a,heapNodeInit(3)); */
  /* heapInsert(&a,heapNodeInit(6)); */
  /* heapInsert(&a,heapNodeInit(5)); */
  /* heapInsert(&a,heapNodeInit(8)); */
  /* heapInsert(&a,heapNodeInit(9)); */

  /* heapInsert(&a,heapNodeInit(9)); */
  /* heapInsert(&a,heapNodeInit(8)); */
  /* heapInsert(&a,heapNodeInit(5)); */
  /* heapInsert(&a,heapNodeInit(6)); */
  /* heapInsert(&a,heapNodeInit(3)); */
  /* heapInsert(&a,heapNodeInit(1)); */

  heapInsert(&a,heapNodeInit(35));
  heapInsert(&a,heapNodeInit(33));
  heapInsert(&a,heapNodeInit(42));
  heapInsert(&a,heapNodeInit(10));
  heapInsert(&a,heapNodeInit(14));
  heapInsert(&a,heapNodeInit(19));
  heapInsert(&a,heapNodeInit(27));
  heapInsert(&a,heapNodeInit(44));
  heapInsert(&a,heapNodeInit(26));
  heapInsert(&a,heapNodeInit(31));
  

  heapDisplay(&a);


  /* HeapNode* a = heapNodeInit(10); */
  /* printf("%d\n",a->weight); */
  
  return 0;
}
