
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"utils.h"

#define STRING_LENGHT 32

int main()
{
    int op;
    char a[STRING_LENGHT] = {0};

    printf("Hola aquí puedes capturar un int: ");
    scanf("%d", &op);

    printf("Tu int es: %d\n", op);

    stdinFlush();
    printf("Aquí puedes captura un string: ");
    getString(a, 32);

    printf("Tu string es: %s\n", a);

    return 0;
}

