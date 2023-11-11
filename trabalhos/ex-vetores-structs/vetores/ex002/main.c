#include <stdio.h>
#include <stdlib.h>

int main()
{

    int m, n;

    /// Ler variável m (linhas)
    do
    {
        printf("Digite o numero de linhas das matrizes A e B: ");
        scanf("%d", &m);

        if (m < 1 || m > 10)
        {
            printf("\n[ERRO] Valor invalido (digite de 1 a 10)\n");
            system("pause");
            system("cls");
        }
    }
    while (m< 1 || m > 10);

    /// Ler variavel n (colunas)
    do
    {
        printf("Agora o numero de colunas das matrizes A e B: ");
        scanf("%d", &n);

        if (n < 1 || n > 10)
        {
            printf("\n[ERRO] Valor invalido (digite de 1 a 10)\n");
            system("pause");
            system("cls");
        }
    }
    while (n < 1 || n > 10);

    /// Definindo as matrizes
    int matrizA[m][n];
    int matrizB[m][n];
    int matrizC[m][n];

    /// Ler os valores de cada posição da matriz A e B
    for(int i = 0; i < n; i++)
    {
        system("cls");
        printf("Matriz A:\n");
        for(int j = 0; j < n; j++)
        {
            printf("  Valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
        printf("Matriz B:\n");
        for(int j = 0; j < n; j++)
        {
            printf("  Valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    /// Construir matriz C onde possui as somas
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    /// Exibir a matriz C
    system("cls");
    printf("Matriz C:\n");
    for(int i = 0; i < m; i++)
    {
        printf("   ");
        for(int j = 0; j < n; j++)
        {
            printf("[%d]", matrizC[i][j]);
        }
        printf("\n");
    }


    return 0;
}
