#include <stdio.h>

int main()
{
    int n, quantidadeNegativos;

    printf("Qual a ordem da matriz?\n");
    scanf("%d", &n);

    int matriz[n][n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("Elemento [%d,%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\nDiagonal principal: ");

    for(int i=0; i<n; i++) {
        printf("%d ", matriz[i][i]);
    }

    quantidadeNegativos=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matriz[i][j] < 0) {
                quantidadeNegativos++;
            }
        }
    }

    printf("\n\nQuantidade de negativos: %d\n", quantidadeNegativos);

    return 0;
}
