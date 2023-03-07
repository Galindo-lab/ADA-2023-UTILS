

/**
 * Si se salta la captura del string coloca esta funcion antes
 * y el problema deberia solucionarse
 * @author luis Eduardo Galindo Amaya
 */
void stdinFlush()
{
  // descarta el ultimo '\n' en stdin
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

/**
 * Validar si un caracter es numerico
 * @author Luis Eduardo Galindo Amaya
 * @param ch caracter a evaluar
 */
char isNumeric(char ch)
{
  return ch >= '0' && ch <= '9';
}

/**
 * Convertir mayuscula a minuscula
 * @param str puntero a array de chars
 * @author Luis Eduardo Galindo Amaya
 */
void strUpper(char *str)
{
  for (char *i = str; *i != 0; i++)
  {
    if (!isNumeric(*i))
    {
      // si no es numerico convertir a mayuscula
      *i &= ~32;
    }
  }
}

/**
 * Capturar string
 * @author Luis Eduardo Galindo Amaya
 * @param str apuntador a un array de chars
 * @param lenght
 */
void getString(char *str, int max_lenght)
{
  // captura el string
  fgets(str, max_lenght, stdin);

  // reemplaza el ultimo caracter con el terminador
  char *p;
  if ((p = strchr(str, '\n')) != NULL)
    *p = '\0';

  strUpper(str);
}

/**
 * Longitud de la lista
 * @param direccion a la lista
 * @return numero de nodos
 */
int len(LinkedList *list)
{
  return linkedListLenght(list);
}

/**
 * Crear una nueva entrada para la lista, paras mas informacion consultar
 * linkedListNode.h
 * @param list direccion a la lista
 * @param category CATEGORY_FOOD, CATEGORY_ENTERTAMENT, CATEGORY_FIXED_PAYMENT
 * @param cost valor en dinero
 */
void append(LinkedList *list, char *title, char *album, char *artist)
{
  linkedListInsertLast(list, linkedListNodeCreate(title, album, artist));
}

/**
 * Insertar un nodo en una posicion de la lista
 * @param list direccion a la lista
 * @param node direccion al nodo
 * @param posicion en la lista
 */
void insert(LinkedList *list, LinkedListNode *node, int position)
{
  linkedListInsert(list, node, position);
}

/**
 * Eliminar un nodo de la lista
 * @param list direccion a la lista
 * @param posicion en la lista
 */
void delete(LinkedList *list, int position)
{
  linkedListRemove(list, position);
}

/**
 * Obtener el valor de un nodo de la lista
 * @param direccion a la lista
 * @param posicion del elemento
 * @return puntero al nodo
 */
LinkedListNode *get(LinkedList *list, int position)
{
  return linkedListNodeCopy(linkedListGet(list, position));
}

/**
 * Mostrar todos los valores del nodo
 * @param direccion al nodo
 */
void display(LinkedListNode *node)
{
  linkedListNodeDisplay(node);
}

/**
 * Ordenar la lista
 * @param direccion a la lista
 */
void printLista(LinkedList *lista)
{
  printf("%-33s %-33s %-33s \n", "Titulo", "Album", "Artista");
  for (int i = 0; i < len(lista); i++)
  {
    display(get(lista, i));
    printf("\n");
  }
}

/**
 * Saber cual string es mayor
 * @param str1 string 1
 * @param str2 string 2
 */
int strDiff(char *str1, char *str2)
{
  return strcmp(str1, str2) < 0;
}
