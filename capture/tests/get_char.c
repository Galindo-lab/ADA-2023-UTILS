
#include "../strGet.h"
#include "../charGet.h"


int main()
{
    char a;

    printf("ingrese un caracter: ");
    charGet(&a);

    printf("el caracter capturado es: %c\n", a);

    return 0;
}
