#include <stdio.h>
#include <locale.h>

int main()
{
    int n, quant, x;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite a quantidade de n�meros que voc� ir� digitar:\n");
    scanf("%d", &n);

    for(quant = 1; quant <= n; quant++) //at� que a veriavel quant seja igual a n, ser�o realizados testes e em seguida adicionar mais um para que a quant <= n
    {
        printf("\n Digite: ");
        scanf("%d", &x);

        //apos ser armazenado em x, o valor em que o usuario digitar ser� submetido a testes
        if(x == 0) //testa se � nulo
        {
            printf("\nNULO\n");

        }
        else if(x % 2 != 0) //testa se � impar
        {
            printf("\nEste n�mero � �MPAR e ");
        }
        else if(x % 2 == 0) //testa se � par
        {
            printf("\nEste n�mero � PAR e ");
        }



        if(x > 0) //testa se � positivo ou negativo
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
