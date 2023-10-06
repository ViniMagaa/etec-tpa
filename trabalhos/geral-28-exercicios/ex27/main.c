#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float salario, aumento;

    printf("Insira o seu sal�rio atual para descobrir como ele ficar� depois do aumento: ");
    scanf("%f", &salario);

    if(salario > 0 && salario <= 1000){
        aumento = salario + (salario * 0.2);
        printf("O seu novo sal�rio ficar� R$ %.2f", aumento);
    } else if(salario > 1000 && salario <= 3000) {
        aumento = salario + (salario * 0.15);
        printf("O seu novo sal�rio ficar� R$ %.2f", aumento);
    } else if(salario > 3000 && salario <= 8000) {
        aumento = salario + (salario * 0.10);
        printf("O seu novo sal�rio ficar� R$ %.2f", aumento);
    } else if(salario > 8000) {
        aumento = salario + (salario * 0.5);
        printf("O seu novo sal�rio ficar� R$ %.2f", aumento);
    } else {
        printf("Sal�rio inv�lido");
    }

    printf("\n");

    return 0;
}
