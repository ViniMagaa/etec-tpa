#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int x, y;

    while(x != y) {
        printf("Digite o valor de X:\n");
        scanf("%d", &x);

        printf("\nDigite o valor de Y:\n");
        scanf("%d", &y);

        if(x < y) {
            system("cls");
            printf("Valores digitados em ordem crescente.\n\n");
        }
        else if(y < x) {
            system("cls");
            printf("\nValores digitados em ordem decrescente.\n\n");
        }
    }

    printf("Os valores são iguais, o programa será encerrado.\n");

    return 0;
}
