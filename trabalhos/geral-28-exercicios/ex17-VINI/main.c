#include <stdio.h>
#include <locale.h>

int segundoMaior(void);
int primeiroMaior(void);

int x, y, res, somaFinal = 0;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o primeiro n�mero: ");
    scanf("%d", &x);

    printf("Digite o segundo n�mero: ");
    scanf("%d", &y);

    if(y > x)//Segundo valor maior que o primeiro
    {
        segundoMaior();
        printf("O valor da soma de todos os n�meros �mpares entre %d e %d � %d", x, y, somaFinal);
    }

    if(x > y)//Primeiro valor maior que o segundo
    {
        primeiroMaior();
        printf("O valor da soma de todos os n�meros �mpares entre %d e %d � %d", y, x, somaFinal);
    }

    return 0;
}



int segundoMaior(void)
{
    if(x % 2 != 0)//primeiro valor � �mpar
    {
        for(res = x; res <= y; res += 2)
        {
            somaFinal += res;
        }
    }

    if(x % 2 == 0)//primeiro valor � par
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
    if(y % 2 != 0)//segundo valor � �mpar
    {
        for(res = y; res <= x; res += 2)
        {
            somaFinal += res;
        }
    }

    if(y % 2 == 0)//segundo valor � par
    {
        for(res = y + 1; res <= x; res += 2)
        {
            somaFinal += res;
        }
    }

    return somaFinal;
}
