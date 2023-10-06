#include <stdio.h>
#include <stdlib.h>

int main()
{
    int minutos, valor;
    printf("digite a quantidade de minutos que voce usou: ");
    scanf("%d", &minutos);

    minutos -= 100;
    valor = 50;

    if(minutos <= 0)
    {
        printf("voce vai pagar somente %d", valor);
    }
    else
    {
        minutos * 2;
        valor = valor + minutos;
        printf("voce vai pagar: %d reais", valor);
    }

    return 0;
}
