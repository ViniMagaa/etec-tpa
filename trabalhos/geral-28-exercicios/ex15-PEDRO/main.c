#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int tipo;
    int quantidade;
    int alcool = 0, gasolina = 0, diesel = 0;

    do
    {
        printf("Informe o tipo de combustivel abastecido:\n");
        printf("[1]Álcool\n");
        printf("[2]Gasolina\n");
        printf("[3]Diesel\n");
        printf("[4]Fim\n");
        scanf("%d", &tipo);

        if (tipo != 4)
        {

            printf("Informe a quantidade de combustivel abastecido:");
            scanf("%d", &quantidade);

            switch (tipo)
            {
            case 1:
                alcool = alcool + quantidade;
                break;
            case 2:
                gasolina = gasolina + quantidade;
                break;
            case 3:
                diesel = diesel + quantidade;
                break;
            default:
                printf("Combustivel inválido. Tente novamente.\n\n");

            }
        }
    }
    while (tipo != 4);

    printf("MUITO OBRIGADO!\n");
    printf("Álcool: %d\n", alcool);
    printf("Gasolina: %d\n", gasolina);
    printf("Diesel: %d\n", diesel);

    return 0;
}
