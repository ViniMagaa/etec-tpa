#include <stdio.h>
#include <locale.h>

int main()
{
    int x, res;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite um número: ");
    scanf("%d", &x);

    printf("\nAqui estão os números ímpares de 1 até %d:\n", x);
    for(res = 1; res <= x; res += 2) //para(valor_inicial; valor_final; incremento) {instrução}
    {
        printf("%d\n", res);
    }
    return 0;
}
