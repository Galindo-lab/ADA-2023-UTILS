#include "../glsq.h"

void showList(List* list) {
    for (int i = 0; i < LIST_LEN(list); i++)
    {
        printf("%d: %d\n", i, LIST_GET(int,list,i));
    }
}

int main() {
    List list;
    ListInit(&list);

    // Caso límite: Lista vacía
    printf("Lista vacía:\n");
    printf("Longitud de la lista: %d\n", LIST_LEN(&list));
    printf("Lista vacía? %s\n", LIST_EMPTY(&list) ? "Sí" : "No");
    printf("\n");

    // Insertar elementos en la lista con listInsert
    int element1 = 10;
    int element2 = 20;
    int element3 = 30;

    ListInsert(&list, 0, &element1);
    ListInsert(&list, 1, &element2);
    ListInsert(&list, 2, &element3);

    // Insertar elementos en la lista con push
    int element4 = 40;
    int element5 = 50;
    int element6 = 60;

    LIST_PUSH(&list, &element4);
    LIST_PUSH(&list, &element5);
    LIST_PUSH(&list, &element6);

    // Obtener el valor en una posición
    int value = LIST_GET(int, &list, 1);
    printf("Valor en la posición 1: %d\n", value);

    // Imprimir la longitud de la lista
    int length = LIST_LEN(&list);
    printf("Longitud de la lista: %d\n", length);

    // Imprimir los elementos de la lista
    printf("Elementos de la lista:\n");
    for (int i = 0; i < length; i++) {
        int element = LIST_GET(int, &list, i);
        printf(" Elemento en la posición %d: %d\n", i, element);
    }
    printf("\n");

    // Caso límite: Eliminar todos los elementos
    printf("Eliminar todos los elementos:\n");
    while (!LIST_EMPTY(&list)) {
        int removedElement = LIST_POP(int, &list);
        printf(" Elemento eliminado: %d\n", removedElement);
    }
    printf("Longitud de la lista: %d\n", LIST_LEN(&list));
    printf("Lista vacía? %s\n", LIST_EMPTY(&list) ? "Sí" : "No");
    printf("\n");

    // Liberar la memoria de la lista
    ListFree(&list);

    return 0;
}
