#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;
    int x;

    printf("Digite um n�mero: ");
    scanf("%d", &n);

    printf("Aqui est� a tabuada de %d do 1 ao 10:\n", n);
    x = 1;
    while(x <= 10)
    {
        printf("%d x %d = %d\n", n, x, n * x);
        x = x + 1;
    }

}
