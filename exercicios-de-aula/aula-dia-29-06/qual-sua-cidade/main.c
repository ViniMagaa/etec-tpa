#include <stdio.h>
#include <locale.h>

int main()
{
    int cidade, distancia;

    setlocale(LC_ALL, "Portuguese");
    printf("Qual a cidade que voc� mora? [1]Nova Odessa [2]Sbo [3] Americana [4]Outra\n");
    scanf("%d", &cidade);

    if (cidade == 1) {
        printf("Logo ali\n");
    } else if (cidade == 2) {
        printf("Ol�, vizinho\n");
    } else if (cidade == 3) {
        printf("� nois\n");
    } else {
        printf("Qual a dist�ncia da sua cidade de nascimento? ");
        scanf("%d", &distancia);

        if (distancia > 0 && distancia <= 50){
            printf("T� perto");
        } else if (distancia >= 51 && distancia <= 200){
            printf("T� ficando longe");
        } else {
            printf("Longe pra caramba");
        }

    }
    return 0;
}
