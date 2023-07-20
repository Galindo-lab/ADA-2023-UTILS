#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * @brief Estructura que representa un nodo en la lista enlazada.
 */
typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

/**
 * @brief Estructura que representa una lista enlazada.
 */
typedef struct List
{
    Node *head;
    int length;
} List;

/**
 * @brief Macro para verificar si la lista está vacía.
 *
 * @param LIST Puntero a la lista.
 * @return 1 si la lista está vacía, 0 en caso contrario.
 */
#define LIST_EMPTY(LIST) (((LIST)->head == NULL))

/**
 * @brief Macro para obtener la longitud actual de la lista.
 *
 * @param LIST Puntero a la lista.
 * @return La longitud de la lista.
 */
#define LIST_LEN(LIST) ((LIST)->length)

/**
 * @brief Macro para obtener el valor en una posición
 *
 * @param TYPE Tipo al que se desea convertir el valor.
 * @param LIST Puntero a la lista.
 * @param INDEX Índice de la posición deseada.
 * @return El valor convertido al tipo especificado.
 */
#define LIST_GET(TYPE, LIST, INDEX) \
    (*((TYPE *)(ListGetNode(LIST, INDEX)->data)))

/**
 * @brief Macro para insertar un elemento al final de la lista.
 *
 * @param LIST Puntero a la lista.
 * @param DATA Puntero a los datos a insertar.
 */
#define LIST_PUSH(LIST, DATA) ListInsert(LIST, LIST_LEN(LIST), DATA)

/**
 * @brief Macro para extraer el último elemento de la lista.
 *
 * @param TYPE Tipo al que se desea convertir el valor.
 * @param LIST Puntero a la lista.
 * @return El valor convertido al tipo especificado.
 */
#define LIST_POP(TYPE, LIST) \
    LIST_GET(TYPE, LIST, LIST_LEN(LIST) - 1); \
    ListRemove(LIST, LIST_LEN(LIST) - 1)

/**
 * @brief Crea un nuevo nodo con los datos especificados.
 *
 * @param data Puntero a los datos a almacenar en el nodo.
 * @return Un puntero al nodo creado.
 */
Node *NodeCreate(void *data)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * @brief Inicializa una lista vacía.
 *
 * @param list Puntero a la lista a inicializar.
 */
void ListInit(List *list)
{
    list->head = NULL;
    list->length = 0;
}

/**
 * @brief Obtiene el nodo en la posición especificada de la lista.
 *
 * @param list Puntero a la lista.
 * @param index Índice de la posición deseada.
 * @return Un puntero al nodo en la posición especificada.
 */
Node *ListGetNode(List *list, int index)
{
    assert(index >= 0);
    assert(index < LIST_LEN(list));

    Node *node = list->head;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

/**
 * @brief Inserta un nuevo nodo con los datos en la posición indicada.
 *
 * @param list Puntero a la lista.
 * @param index Índice de la posición en la que se insertará el nodo.
 * @param data Puntero a los datos a almacenar en el nuevo nodo.
 */
void ListInsert(List *list, int index, void *data)
{
    assert(index >= 0);
    assert(index <= LIST_LEN(list));

    Node *newNode = NodeCreate(data);

    if (newNode == NULL)
    {
        printf("ERROR: NodeCreate no puede reservar memoria\n");
        exit(EXIT_FAILURE);
    }

    if (index == 0)
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    else
    {
        Node *prev = ListGetNode(list, index - 1);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    list->length++;
}

/**
 * @brief Elimina el nodo en la posición especificada de la lista.
 *
 * @param list Puntero a la lista.
 * @param index Índice de la posición del nodo a eliminar.
 */
void ListRemove(List *list, int index)
{
    assert(index >= 0);
    assert(index < LIST_LEN(list));

    Node *nodeToRemove;

    if (index == 0)
    {
        nodeToRemove = list->head;
        list->head = nodeToRemove->next;
    }
    else
    {
        Node *prev = ListGetNode(list, index - 1);
        nodeToRemove = prev->next;
        prev->next = nodeToRemove->next;
    }

    free(nodeToRemove);
    list->length--;
}

/**
 * @brief Libera la memoria ocupada por todos los nodos de la lista.
 *
 * @param list Puntero a la lista a liberar.
 */
void ListFree(List *list)
{
    while (!LIST_EMPTY(list))
        ListRemove(list, 0);
}