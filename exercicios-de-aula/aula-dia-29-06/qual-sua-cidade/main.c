#include <stdio.h>
#include <locale.h>

int main()
{
    int cidade, distancia;

    setlocale(LC_ALL, "Portuguese");
    printf("Qual a cidade que você mora? [1]Nova Odessa [2]Sbo [3] Americana [4]Outra\n");
    scanf("%d", &cidade);

    if (cidade == 1) {
        printf("Logo ali\n");
    } else if (cidade == 2) {
        printf("Olá, vizinho\n");
    } else if (cidade == 3) {
        printf("É nois\n");
    } else {
        printf("Qual a distância da sua cidade de nascimento? ");
        scanf("%d", &distancia);

        if (distancia > 0 && distancia <= 50){
            printf("Tá perto");
        } else if (distancia >= 51 && distancia <= 200){
            printf("Tá ficando longe");
        } else {
            printf("Longe pra caramba");
        }

    }
    return 0;
}
