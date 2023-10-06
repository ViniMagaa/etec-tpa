#include <stdio.h>
#include <locale.h>

int main()
{
    int n, quant, x, numDentro = 0, numFora = 0; //numDentro e numFora s�o iguais a zero para evitar erros

    setlocale(LC_ALL, "Portuguese");

    printf("Digite a quantidade de n�meros em que voc� ir� digitar:\n");
    scanf("%d", &n);

    for(quant = 1; quant <= n; quant++) //at� que a veriavel quant seja igual a n, ser�o realizados testes e em seguida adicionar mais um para que a quant <= n
    {
        printf("\n Digite: ");
        scanf("%d", &x);

        //apos ser armazenado em x, o valor em que o usuario digitar ser� submetido a testes
        if(x >= 10 && x <= 20) //se estiver dentro do intervalo de 10 a 20, somar� +1 � variavel numDentro
        {
            numDentro += 1;
        }
        else //caso estiver fora, ir� somar +1 na variavel numFora
        {
            numFora += 1;
        }
    }
    //o loop nao terminar� ate que quant <= n

    printf("\nDos n�meros digitados, %d est�o dentro do intervalo de 10 a 20, e %d est�o fora.\n", numDentro, numFora);

    return 0;
}
