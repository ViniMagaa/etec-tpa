#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, y, soma;
    printf("Escreva o valor de X:");
    scanf("%d", &x);
    printf("Escreva o valor de Y:");
    scanf("%d", &y);

    soma= x + y;
    printf("O valor de X + Y é: %d", soma);

    return 0;
}