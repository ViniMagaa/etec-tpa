#include<stdio.h>
#include <locale.h>

int main() {
    int x, y, z;
	setlocale(LC_ALL, "Portuguese");

	printf("Insira o primeiro número\n");
	scanf("%d", &x);
	printf("Insira o segundo número\n");
	scanf("%d", &y);

	z = x + y;

	printf("Esse é o valor da soma desses dois números %d\n", z);

	return 0;

}
