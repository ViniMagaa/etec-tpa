#include<stdio.h>
#include <locale.h>

int main() {
    int x, y, z;
	setlocale(LC_ALL, "Portuguese");

	printf("Insira o primeiro n�mero\n");
	scanf("%d", &x);
	printf("Insira o segundo n�mero\n");
	scanf("%d", &y);

	z = x + y;

	printf("Esse � o valor da soma desses dois n�meros %d\n", z);

	return 0;

}
