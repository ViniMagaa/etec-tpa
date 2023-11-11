#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;

    do
    {
        system("cls");
        printf("Digite o numero da ordem da matriz: ");
        scanf("%d", &n);

        if (n < 1 || n > 10)
        {
            printf("\n[ERRO] Valor invalido (digite de 1 a 10)\n");
            system("pause");
        }
    }
    while (n < 1 || n > 10);

    double matriz[n][n];

    /// Ler os valores de cada posição da matriz
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("Valor da posicao [%d][%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }

    int opcao, opcao2, indice;
    double somaPositivos = 0, matrizElevada[n][n];
    do
    {
        system("cls");

        printf("Selecione sua acao:");
        printf("\n [0] Mostrar soma dos positivos");
        printf("\n [1] Mostrar elementos de uma linha");
        printf("\n [2] Mostrar elementos de uma coluna");
        printf("\n [3] Mostrar os elementos da diagonal principal");
        printf("\n [4] Elevar os numeros negativos da matriz ao quadrado");
        printf("\n [5] Sair \n");
        scanf("%d", &opcao);

        system("cls");
        switch(opcao)
        {
            case 0: /// Mostrar soma dos positivos
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if (matriz[i][j] >= 0)
                        {
                            somaPositivos += matriz[i][j];
                        }
                    }
                }
                printf("Soma dos numeros positivos: %.2lf \n", somaPositivos);
                somaPositivos = 0; // Resetar o numero da soma
                break;
            case 1: /// Mostrar elementos de uma linha
                do
                {
                    printf("Digite o indice da linha: ");
                    scanf("%d", &indice);

                    if (indice < 0 || indice > n-1)
                    {
                        printf("\n[ERRO] Valor invalido (digite de 0 a %d)\n", n-1);
                        system("pause");
                    }
                }
                while (indice < 0 || indice > n-1);
                printf("Numeros da linha %d: \n", indice);
                for (int i = 0; i < n; i++)
                {
                    printf(" %.2lf \n", matriz[indice][i]);
                }
                break;
            case 2: /// Mostrar elementos de uma coluna
                do
                {
                    printf("Digite o indice da coluna: ");
                    scanf("%d", &indice);

                    if (indice < 0 || indice > n-1)
                    {
                        printf("\n[ERRO] Valor invalido (digite de 0 a %d)\n", n-1);
                        system("pause");
                    }
                }
                while (indice < 0 || indice > n-1);
                printf("Numeros da coluna %d: \n", indice);
                for (int i = 0; i < n; i++)
                {
                    printf(" %.2lf \n", matriz[i][indice]);
                }
                break;
            case 3: /// Mostrar elementos da diagonal principal
                indice = 0; // Resetar o indice
                printf("Elementos da diagonal principal: \n");
                for(int i = 0; i < n; i++)
                {
                    // Exibe o elemento da linha 'i' na posição 'indice'
                    printf(" %.2lf \n", matriz[i][indice]);
                    // Índice da diagonal aumenta a cada linha (n)
                    indice++;
                }
                break;
            case 4: /// Elevar os numeros negativos da matriz ao quadrado
                // Definir e exibir a matriz elevada
                printf("Matriz com os numeros negativos elevados: \n");
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        matrizElevada[i][j] = matriz[i][j];
                        if(matriz[i][j] < 0)
                        {
                            matrizElevada[i][j] = pow(matriz[i][j], 2);
                        }
                        printf(" %.2lf \n", matrizElevada[i][j]);
                    }
                }
                do
                {
                    printf("\nVoce deseja substituir a matriz original?");
                    printf("\n [0] Sim");
                    printf("\n [1] Nao \n");
                    scanf("%d", &opcao2);
                    if(opcao2 < 0 || opcao2 > 1)
                    {
                        printf("\n[ERRO] Valor invalido (digite de 0 ou 1)\n");
                        system("pause");
                    }
                }
                while (opcao2 < 0 || opcao2 > 1);
                if (opcao2 == 0) // Caso sim, a matriz sera substituida
                {
                    for(int i = 0; i < n; i++)
                    {
                        for(int j = 0; j < n; j++)
                        {
                            matriz[i][j] = matrizElevada[i][j];
                        }
                    }
                }
                break;
            case 5:
                printf("Ate mais!\n");
                break;
            default:
                printf("[ERRO] Opcao invalida!\n");
                break;
        }
        system("pause");
    }
    while(opcao != 5);

    return 0;
}
