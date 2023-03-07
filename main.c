
#include "linkedList.h"
#include "linkedListNode.h"

/**
 * Longitud de la lista
 * @param direccion a la lista
 * @return numero de nodos
 */
int len(LinkedList *list);

/**
 * Crear una nueva entrada para la lista, para mas informacion consultar
 * linkedListNode.h
 */
void append(LinkedList *list, char *title, char *album, char *artist);

/**
 * Insertar un nodo en una posicion de la lista
 * @param list direccion a la lista
 * @param node direccion al nodo
 * @param posicion en la lista
 */
void insert(LinkedList *list, LinkedListNode *node, int position);

/**
 * Eliminar un nodo de la lista
 * @param list direccion a la lista
 * @param posicion en la lista
 */
void delete(LinkedList *list, int position);

/**
 * Obtener el valor de un nodo de la lista
 * @param direccion a la lista
 * @param posicion del elemento
 * @return puntero al nodo
 */
LinkedListNode *get(LinkedList *list, int position);


/**
 * Mostrar todos los valores del nodo
 * @param direccion al nodo
 */
void display(LinkedListNode *node);

int main(void)
{
    LinkedList lista;
    linkedListInit(&lista); // inicializar la lista 

    append(&lista, "titulo 0", "album 0", "artist 0");
    append(&lista, "titulo 1", "album 1", "artist 1");

    printf("Nodos de prueba 1 --------------------\n");
    for (int i = 0; i < len(&lista); i++)
    {
        display(get(&lista, i));
        printf("\n");
    }
    
    LinkedListNode *foo = get(&lista, 1); // guardar el valor del nodo
    delete(&lista, 1); // eliminamos el nodo guardado

    printf("Nodos de prueba 2 -------------------\n");
    for (int i = 0; i < len(&lista); i++)
    {
        display(get(&lista, i));
        printf("\n");
    }

    insert(&lista, foo, 0); // insertamos el valor guardado pero ahora al inicio de la lista

    printf("Nodos de prueba 3 -------------------\n");
    for (int i = 0; i < len(&lista); i++)
    {
        display(get(&lista, i));
        printf("\n");
    }

    linkedListFree(&lista); // liberamos memoria

    return 0;
}

/**
 * Implementacion de las funciones 
*/
int len(LinkedList *list)
{
  return linkedListLenght(list);
}

void append(LinkedList *list, char *title, char *album, char *artist)
{
  linkedListInsertLast(list, linkedListNodeCreate(title, album, artist));
}

void insert(LinkedList *list, LinkedListNode *node, int position)
{
  linkedListInsert(list, node, position);
}

void delete(LinkedList *list, int position)
{
  linkedListRemove(list, position);
}

LinkedListNode *get(LinkedList *list, int position)
{
  return linkedListNodeCopy(linkedListGet(list, position));
}

void display(LinkedListNode *node)
{
  linkedListNodeDisplay(node);
}