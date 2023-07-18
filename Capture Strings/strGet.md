# Ejemplo `strGet`

```C
#include "strGet.h"

#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 32

int main()
{
    int op;
    char strPrueba[ARRAY_SIZE] = {0};

    printf("capturar un int: ");
    scanf("%d", &op);
    printf("Tu int es: %d\n", op);

    /* Esta funcion vacia manualmente el buffer 
    GBD no puede usar fflush por lo que este arreglo 
    es necesario */
    stdinFlush(); 

    printf("Captura un string: ");
    strGet(strPrueba, ARRAY_SIZE);

    printf("Tu string es: %s\n", strPrueba);

    strLower(strPrueba);
    printf("Tu string en minusculas es: %s\n", strPrueba);

    strUpper(strPrueba);
    printf("Tu string mayusculas es: %s\n", strPrueba);
    return 0;
}
```

## Metodos de `strGet.h`
- `void stdinFlush()`: Vacia el BUfeer de manera manual.
- `char isAlphabetic(unsigned int ch)`: Valida si un caracter una letra.
- `void strUpper(char *str)`: Convierte todas las letras a mayusculas.
- `void strLower(char *str)`: Convierte todas las letras a minusculas.
- `void strGet(char *str, int max_lenght)`: Captura un array de un tamaño fijo.