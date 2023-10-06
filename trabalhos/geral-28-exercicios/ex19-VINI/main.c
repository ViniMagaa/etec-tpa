#include <stdio.h>
#include <locale.h>

int main()
{
    int n, quant, x, numDentro = 0, numFora = 0; //numDentro e numFora são iguais a zero para evitar erros

    setlocale(LC_ALL, "Portuguese");

    printf("Digite a quantidade de números em que você irá digitar:\n");
    scanf("%d", &n);

    for(quant = 1; quant <= n; quant++) //até que a veriavel quant seja igual a n, serão realizados testes e em seguida adicionar mais um para que a quant <= n
    {
        printf("\n Digite: ");
        scanf("%d", &x);

        //apos ser armazenado em x, o valor em que o usuario digitar será submetido a testes
        if(x >= 10 && x <= 20) //se estiver dentro do intervalo de 10 a 20, somará +1 à variavel numDentro
        {
            numDentro += 1;
        }
        else //caso estiver fora, irá somar +1 na variavel numFora
        {
            numFora += 1;
        }
    }
    //o loop nao terminará ate que quant <= n

    printf("\nDos números digitados, %d estão dentro do intervalo de 10 a 20, e %d estão fora.\n", numDentro, numFora);

    return 0;
}
