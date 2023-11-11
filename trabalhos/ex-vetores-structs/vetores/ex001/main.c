#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

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

    system("cls");

    /// Verificar o maior valor de cada linha da matriz
    for(int i = 0; i < n; i++)
    {
        int maiorValorLinha = 0;

        for(int j = 0; j < n; j++)
        {
            if(matriz[i][j] > maiorValorLinha) {
                maiorValorLinha = matriz[i][j];
            }
        }

        printf("Maior valor da linha %d: %d \n", i, maiorValorLinha);
    }

    return 0;
}
