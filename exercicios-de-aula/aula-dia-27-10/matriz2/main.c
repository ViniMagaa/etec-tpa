#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;

    printf("Qual a quantidade de linhas da matriz?\n");
    scanf("%d", &m);
    printf("Qual a quantidade de colunas da matriz?\n");
    scanf("%d", &n);

    int matriz[m][n];

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("Elemento [%d,%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\nValores negativos: ");

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matriz[i][j] < 0) {
                printf("%d ", matriz[i][j]);
            }
        }
    }

    return 0;
}
