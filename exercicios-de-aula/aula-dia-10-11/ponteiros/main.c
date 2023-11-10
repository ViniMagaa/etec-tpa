#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Digite o valor de X: ");
    scanf("%d", &x);
    int *ponteiroParaX = &x;

    printf("Valor de X: %d\n", x);
    printf("Endereco de X: %p\n", (void *)&x);
    printf("Valo do ponteiro de X: %d\n", *ponteiroParaX);

    return 0;
}
