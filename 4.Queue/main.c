#include "Queue.h"

#include <stdio.h>

void showList(Queue *queue)
{
    for (int i = 0; i < QUEUE_SIZE(queue); i++)
    {
        printf("%d: %d\n", i, LIST_GET(int, queue, i));
    }
}

int main()
{
    Queue queue;
    ListInit(&queue);

    // Caso límite: Lista vacía
    printf("Lista vacía:\n");
    printf("Longitud de la lista: %d\n", QUEUE_SIZE(&queue));
    printf("Lista vacía? %s\n", QUEUE_EMPTY(&queue) ? "Sí" : "No");
    printf("\n");

    // Insertar elementos en la lista con listInsert
    int element1 = 10;
    int element2 = 20;
    int element3 = 30;

    QUEUE_ENQUEUE(&queue, &element1);
    QUEUE_ENQUEUE(&queue, &element2);
    QUEUE_ENQUEUE(&queue, &element3);

    // Imprimir la longitud de la lista
    int size = QUEUE_SIZE(&queue);
    printf("Longitud de la lista: %d\n", size);

    // Imprimir los elementos de la lista
    printf("Elementos de la lista:\n");
    for (int i = 0; i < size; i++)
    {
        int element = LIST_GET(int, &queue, i);
        printf(" Elemento en la posición %d: %d\n", i, element);
    }
    printf("\n");

    // REAR y FRONT
    printf("Elemento al inicio: %d\n", QUEUE_FRONT(int, &queue));

    printf("Elemento al final: %d\n", QUEUE_REAR(int, &queue));

    // Caso límite: Eliminar todos los elementos
    printf("\nEliminar todos los elementos:\n");
    while (!QUEUE_EMPTY(&queue))
    {
        int removedElement = QUEUE_DEQUEUE(int, &queue);
        printf(" Elemento eliminado: %d\n", removedElement);
    }
    printf("Longitud de la lista: %d\n", QUEUE_SIZE(&queue));
    printf("Lista vacía? %s\n", QUEUE_EMPTY(&queue) ? "Sí" : "No");
    printf("\n");

    // Liberar la memoria de la lista
    QUEUE_FREE(&queue);

    return 0;
}
