#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    float dardo1 = 0, dardo2 = 0, dardo3 = 0;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite o valor da distância em metros do primeiro dardo: \n");
    scanf("%f", &dardo1);
    fflush(stdin);

    printf("Digite o valor da distância em metros do segundo dardo: \n");
    scanf("%f", &dardo2);
    fflush(stdin);

    printf("Digite o valor da distância em metros do terceiro dardo: \n");
    scanf("%f", &dardo3);
    fflush(stdin);

    if(dardo1 > dardo2 && dardo1 > dardo3) {
        printf("\nO primeiro dardo percorreu a maior distância.");
    } else if(dardo2 > dardo1 && dardo2 > dardo3) {
        printf("\nO segundo dardo percorreu a maior distância.");
    } else if(dardo3 > dardo1 && dardo3 > dardo2) {
        printf("\nO terceiro dardo percorreu a maior distância.");
    } else {
        printf("\nNenhum dardo possui a maior distância\n");
    }

    return 0;
}
