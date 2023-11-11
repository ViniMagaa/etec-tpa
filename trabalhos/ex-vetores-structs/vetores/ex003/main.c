#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, somaTotal = 0;

    do
    {
        system("cls");
        printf("Digite o numero da ordem da matriz: ");
        scanf("%d", &n);

        if (n < 1 || n > 10)
        {
            printf("\n[ERRO] Valor invalido (digite de 1 a 10)\n");
            system("pause");
        }
    }
    while (n < 1 || n > 10);

    int matriz[n][n];

    /// Ler os valores de cada posição da matriz
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("Valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    /// Somar os elementos acima da diagonal principal
    int indiceDiagonal = 0;
    for(int i = 0; i < n; i++)
    {
        // Define com o indice que começará a ler a partir da diagonal
        for(int j = indiceDiagonal+1; j < n; j++)
        {
            somaTotal += matriz[i][j];
        }
        // Índice da diagonal aumenta a cada linha (n)
        indiceDiagonal++;
    }

    printf("\nSoma dos elementos da matriz acima da diagonal principal: %d\n", somaTotal);

    return 0;
}
