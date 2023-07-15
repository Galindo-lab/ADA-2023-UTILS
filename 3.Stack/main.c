#include <stdio.h>
#include "Stack.h"

void showList(Stack* list) {
    for (int i = 0; i < LIST_LEN(list); i++)
    {
        printf("%d: %d\n", i, LIST_GET(int,list,i));
    }
}

int main() {
    Stack stack;
    STACK_INIT(&stack);

    // Caso límite: stack vacío
    printf("stack vacío:\n");
    printf("Longitud del stack: %d\n", STACK_SIZE(&stack));
    printf("stack vacío? %s\n", STACK_EMPTY(&stack) ? "Sí" : "No");
    printf("\n");

    // Insertar elementos en el stack con push
    int element1 = 10;
    int element2 = 20;
    int element3 = 30;

    STACK_PUSH(&stack, &element1);
    STACK_PUSH(&stack, &element2);
    STACK_PUSH(&stack, &element3);

    // Imprimir la longitud del stack
    int size = STACK_SIZE(&stack);
    printf("Longitud del stack: %d\n", size);

    // Imprimir los elementos del stack
    printf("Elementos del stack:\n");
    for (int i = 0; i < size; i++) {
        int element = LIST_GET(int, &stack, i);
        printf(" Elemento en la posición %d: %d\n", i, element);
    }
    printf("\n");

    // Caso límite: Eliminar todos los elementos
    printf("Eliminar todos los elementos:\n");
    while (!STACK_EMPTY(&stack)) {
        int removedElement = STACK_POP(int, &stack);
        printf(" Elemento eliminado: %d\n", removedElement);
    }
    printf("Longitud del stack: %d\n", STACK_SIZE(&stack));
    printf("stack vacío? %s\n", STACK_EMPTY(&stack) ? "Sí" : "No");
    printf("\n");

    // Liberar la memoria del stack
    STACK_FREE(&stack);

    return 0;
}
