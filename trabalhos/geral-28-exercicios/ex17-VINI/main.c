#include <stdio.h>
#include <locale.h>

int segundoMaior(void);
int primeiroMaior(void);

int x, y, res, somaFinal = 0;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o primeiro número: ");
    scanf("%d", &x);

    printf("Digite o segundo número: ");
    scanf("%d", &y);

    if(y > x)//Segundo valor maior que o primeiro
    {
        segundoMaior();
        printf("O valor da soma de todos os números ímpares entre %d e %d é %d", x, y, somaFinal);
    }

    if(x > y)//Primeiro valor maior que o segundo
    {
        primeiroMaior();
        printf("O valor da soma de todos os números ímpares entre %d e %d é %d", y, x, somaFinal);
    }

    return 0;
}



int segundoMaior(void)
{
    if(x % 2 != 0)//primeiro valor é ímpar
    {
        for(res = x; res <= y; res += 2)
        {
            somaFinal += res;
        }
    }

    if(x % 2 == 0)//primeiro valor é par
    {
        for(res = x + 1; res <= y; res += 2)
        {
            somaFinal += res;
        }
    }

    return somaFinal;
}



int primeiroMaior(void)
{
    if(y % 2 != 0)//segundo valor é ímpar
    {
        for(res = y; res <= x; res += 2)
        {
            somaFinal += res;
        }
    }

    if(y % 2 == 0)//segundo valor é par
    {
        for(res = y + 1; res <= x; res += 2)
        {
            somaFinal += res;
        }
    }

    return somaFinal;
}
