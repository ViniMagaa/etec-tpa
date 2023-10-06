#include <stdio.h>
#include <locale.h>

int main()
{
    int n, quant, x;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite a quantidade de números que você irá digitar:\n");
    scanf("%d", &n);

    for(quant = 1; quant <= n; quant++) //até que a veriavel quant seja igual a n, serão realizados testes e em seguida adicionar mais um para que a quant <= n
    {
        printf("\n Digite: ");
        scanf("%d", &x);

        //apos ser armazenado em x, o valor em que o usuario digitar será submetido a testes
        if(x == 0) //testa se é nulo
        {
            printf("\nNULO\n");

        }
        else if(x % 2 != 0) //testa se é impar
        {
            printf("\nEste número é ÍMPAR e ");
        }
        else if(x % 2 == 0) //testa se é par
        {
            printf("\nEste número é PAR e ");
        }



        if(x > 0) //testa se é positivo ou negativo
        {
            printf("POSITIVO\n");
        }
        else if(x < 0)
        {
            printf("NEGATIVO\n");
        }
    }

    return 0;
}
