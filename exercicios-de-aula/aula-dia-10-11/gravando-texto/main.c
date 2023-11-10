#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    int i;
    int result;

    system("cls");

    arq = fopen("ArqGrav.txt", "wt");

    if (arq == NULL)
    {
        printf("Problemas na Cria��o do Arquivo.");
        return 0;
    }

    for(i = 1; i < 150; i++)
    {
        // A fun��o fprintf devolve o n�mero de bytes gravados
        result = fprintf(arq, "Linha %d\n", i);
        if (result == EOF) // EOF se houve erro ao gravar
            printf("Erro na Grava��o\n");
    }
    fclose(arq);

    return 0;
}
