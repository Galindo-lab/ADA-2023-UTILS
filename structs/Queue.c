typedef List Queue;

/**
 * @brief Inicializa una cola vacía.
 *
 * @param QUEUE Puntero a la cola a inicializar.
 */
#define QUEUE_INIT(QUEUE) ListInit(STACK);

/**
 * @brief Agrega un elemento a la cola.
 *
 * @param QUEUE Puntero a la cola.
 * @param DATA Elemento a agregar.
 */
#define QUEUE_ENQUEUE(QUEUE, DATA) LIST_PUSH(QUEUE, DATA)

/**
 * @brief Elimina y devuelve el primer elemento de la cola.
 *
 * @param TYPE Tipo de datos de los elementos de la cola.
 * @param QUEUE Puntero a la cola.
 * @return El primer elemento de la cola.
 */
#define QUEUE_DEQUEUE(TYPE, QUEUE) \
    LIST_GET(TYPE, QUEUE, 0);      \
    ListRemove(QUEUE, 0)

/**
 * @brief Verifica si la cola está vacía.
 *
 * @param QUEUE Puntero a la cola.
 * @return 1 si la cola está vacía, 0 en caso contrario.
 */
#define QUEUE_EMPTY(QUEUE) LIST_EMPTY(QUEUE)

/**
 * @brief Obtiene el número de elementos en la cola.
 *
 * @param QUEUE Puntero a la cola.
 * @return El número de elementos en la cola.
 */
#define QUEUE_SIZE(QUEUE) LIST_LEN(QUEUE)

/**
 * @brief Obtiene el primer elemento de la cola sin eliminarlo.
 *
 * @param TYPE Tipo de datos de los elementos de la cola.
 * @param QUEUE Puntero a la cola.
 * @return El primer elemento de la cola.
 */
#define QUEUE_FRONT(TYPE, QUEUE) LIST_GET(TYPE, QUEUE, 0)

/**
 * @brief Obtiene el último elemento de la cola sin eliminarlo.
 *
 * @param TYPE Tipo de datos de los elementos de la cola.
 * @param QUEUE Puntero a la cola.
 * @return El último elemento de la cola.
 */
#define QUEUE_REAR(TYPE, QUEUE) \
    LIST_GET(TYPE, QUEUE, LIST_LEN(QUEUE) - 1)

/**
 * @brief Libera la memoria utilizada por la cola.
 *
 * @param QUEUE Puntero a la cola.
 */
#define QUEUE_FREE(QUEUE) ListFree(QUEUE);
