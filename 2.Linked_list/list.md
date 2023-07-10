# LinkedList.h

El código proporcionado es un conjunto de métodos que controlan una lista enlazada simple. Aquí está la descripción de su funcionalidad:

## Métodos
- `ListEmpty(List *list)`: Verifica si la lista está vacía.
- `ListLenght(List *list)`: Devuelve la cantidad de nodos en la lista.
- `ListInit(List *list)`: Inicializa una lista vacía.
- `ListGetNode(List *list, int index)`: Devuelve un puntero al nodo en la posición especificada.
- `ListInsert(List *list, int index, void *data)`: Inserta un nuevo elemento en la lista en la posición especificada.
- `ListRemove(List *list, int index)`: Elimina el nodo en la posición especificada de la lista.
- `ListFree(List *list)`: Libera la memoria asignada para todos los nodos de la lista.

## Macros
- `LIST_GET(TYPE, LIST, INDEX)` obtener el valor en una posición determinada de la lista y convertirlo a un tipo de datos específico.

## Ejemplo
```C
#include "LinkedList.h"

void showList(List* list);

int main()
{
    List a = ListInit(&a);

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
    for (int i = 0; i < ListLenght(list); i++)
    {
        printf("%d: %.3f\n", i, LIST_GET(float,list,i));
    }
}
```