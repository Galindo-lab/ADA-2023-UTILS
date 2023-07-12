#include "LinkedList2.h"

void showList(List* list);

int main()
{
    List a; ListInit(&a);

    /********************
     * Agregar elementos
     ********************/
    puts("\nAgregar elementos");

    for (int i = 0; i < 10; i++)
    {
        // insertar 10 flotantes
        ListInsert(&a, i, calloc(1, sizeof(float)));

        // podemos modificar los elementos de la lista
        float* elementValue = &LIST_GET(float, &a, i);

        *elementValue = i;
    }
    
    showList(&a);

    /*********************
     * Eliminar elementos
     *********************/
    puts("\nEliminar elementos");

    ListRemove(&a, 3);
    showList(&a);

    /**
     * Liberar memoria de la lista
     */
    ListFree(&a);
    return 0;
}


void showList(List* list) {
    for (int i = 0; i < ListLength(list); i++)
    {
        printf("%d: %.3f\n", i, LIST_GET(float,list,i));
    }
}