typedef List Stack;

/**
 * @brief Macro para inicializar un Stack
 * 
 * @param STACK Puntero a el stack
 */
#define STACK_INIT(STACK) ListInit(STACK);

/**
 * @brief Macro para insertar un elemento en el stack
 *
 * @param STACK Puntero a el stack.
 * @param DATA Puntero a los datos a insertar.
 */
#define STACK_PUSH(STACK, DATA) LIST_PUSH(STACK, DATA)

/**
 * @brief Macro para extraer el último elemento de el stack.

 * @param TYPE Tipo al que se desea convertir el valor.
 * @param STACK Puntero a el stack.
 * @return El valor convertido al tipo especificado.
 */
#define STACK_POP(TYPE, STACK) LIST_POP(TYPE, STACK)

/**
 * @brief Macro para examinar el primer elemento del stack
 *
 * @param TYPE Tipo al que se desea convertir el valor.
 * @param STACK Puntero a el stack.
 * @return El valor del primer elemento del stack
 */
#define STACK_TOP(TYPE, STACK) LIST_GET(TYPE, STACK, 0)

/**
 * @brief Macro para verificar si el stack está vacío.
 *
 * @param STACK Puntero a el stack.
 * @return 1 si el stack está vacía, 0 en caso contrario.
 */
#define STACK_EMPTY(STACK) LIST_EMPTY(STACK)

/**
 * @brief Macro para obtener la cantidad de elementos en el stack
 * 
 * @param STACK Puntero a el stack.
 * @return La longitud de el stack.
 */
#define STACK_SIZE(STACK) LIST_LEN(STACK)


/**
 * @brief Macro para liberar la memoria del stack
 * 
 */
#define STACK_FREE(STACK) ListFree(STACK); 