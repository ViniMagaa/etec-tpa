#include <stdio.h>
#include <locale.h>

int main()
{
    int x, res;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite um n�mero: ");
    scanf("%d", &x);

    printf("\nAqui est�o os n�meros �mpares de 1 at� %d:\n", x);
    for(res = 1; res <= x; res += 2) //para(valor_inicial; valor_final; incremento) {instru��o}
    {
        printf("%d\n", res);
    }
    return 0;
}
