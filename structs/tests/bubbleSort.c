#include "../LinkedList.h"

// Función principal de Bubble Sort
void bubbleSort(List* list)
{
    int i, j;
    int length = LIST_LEN(list);

    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            int* current = &LIST_GET(int, list, j);
            int* next = &LIST_GET(int, list, j + 1);

            // Intercambiar elementos si el siguiente es menor
            if (*current > *next)
            {
                int temp = *current;
                *current = *next;
                *next = temp;
            }
        }
    }
}

int main()
{
    List list;
    ListInit(&list);

    // Insertar elementos en la lista
    int element1 = 30;
    int element2 = 10;
    int element3 = 50;
    int element4 = 20;
    int element5 = 40;

    LIST_PUSH(&list, &element1);
    LIST_PUSH(&list, &element2);
    LIST_PUSH(&list, &element3);
    LIST_PUSH(&list, &element4);
    LIST_PUSH(&list, &element5);

    // Imprimir lista antes de ordenar
    printf("Lista antes de ordenar:\n");
    for (int i = 0; i < LIST_LEN(&list); i++)
    {
        int element = LIST_GET(int, &list, i);
        printf("%d ", element);
    }
    printf("\n");

    // Aplicar Bubble Sort a la lista
    bubbleSort(&list);

    // Imprimir lista después de ordenar
    printf("Lista después de ordenar:\n");
    for (int i = 0; i < LIST_LEN(&list); i++)
    {
        int element = LIST_GET(int, &list, i);
        printf("%d ", element);
    }
    printf("\n");

    // Liberar memoria de la lista
    ListFree(&list);

    return 0;
}
