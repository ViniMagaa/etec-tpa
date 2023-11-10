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
        printf("Problemas na Criação do Arquivo.");
        return 0;
    }

    for(i = 1; i < 150; i++)
    {
        // A função fprintf devolve o número de bytes gravados
        result = fprintf(arq, "Linha %d\n", i);
        if (result == EOF) // EOF se houve erro ao gravar
            printf("Erro na Gravação\n");
    }
    fclose(arq);

    return 0;
}
