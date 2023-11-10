#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *arq;
    char Linha[100];
    char result;
    int i;

    system("cls");

    // Abrir um arquivo texto
    arq = fopen("ArqTeste.txt", "rt");

    if (arq == NULL) // Se houver um erro
    {
        printf("Problemas na abertura do arquivo.");
        return 0;
    }

    i = 1;
    while (!feof(arq))
    {
        // Lê uma linha (mesmo com o '\n'
        result = fgets(Linha, 100, arq);
        if (result)
        {
            printf("Linha %d: %s", i, Linha);
            i++;
        }
    }
    fclose(arq);

    return 0;
}
