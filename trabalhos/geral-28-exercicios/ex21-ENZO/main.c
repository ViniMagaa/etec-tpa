#include<stdio.h>
#include<stdlib.h>

int main ()
{
    float num1, num2, resultado;
    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);
    while(num2 == 0)
    {
        printf("Divisão impossível. Digite o segundo numero novamente: ");
        scanf("%f", &num2);
    }
    resultado = num1 / num2;
    printf("o resultado da divisao entre %f e %f e %f", num1, num2, resultado);
}
