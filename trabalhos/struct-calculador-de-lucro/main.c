#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    char nome[50];
    float valor_bruto;
    float valor_produto;
    int quantidades_vendidas;
} Produto;

int main()
{
    int quantidade_produtos;
    float lucro;

    setlocale(LC_ALL, "Portuguese");


    printf("   ___      _         _         _              _       _ \n");
    printf("  / __|__ _| |__ _  _| |__ _ __| |___ _ _   __| |___  | |_  _ __ _ _ ___  \n");
    printf(" | (__/ _` | / _| || | / _` / _` / _ \\ '_| / _` / -_) | | || / _| '_/ _ \\ \n");
    printf("  \\___\\__,_|_\\__|\\_,_|_\\__,_\\__,_\\___/_|   \\__,_\\___| |_|\\_,_\\__|_| \\___/ \n");

    printf("\nQuantos produtos você vai digitar?\n");
    scanf("%d", &quantidade_produtos);

    Produto produtos[quantidade_produtos];

    for(int i=0; i<quantidade_produtos; i++) {
        system("cls");
        printf("[PRODUTO %d]\n\n", i+1);
        printf("Qual o nome do produto?\n");
        scanf("%s", produtos[i].nome);

        printf("Qual o valor unitário para produzir o produto?\n");
        scanf("%f", &produtos[i].valor_bruto);

        printf("Qual o valor unitário em que o produto é vendido?\n");
        scanf("%f", &produtos[i].valor_produto);

        printf("Quantas unidades foram vendidas?\n");
        scanf("%d", &produtos[i].quantidades_vendidas);

        lucro += (produtos[i].valor_produto - produtos[i].valor_bruto) * produtos[i].quantidades_vendidas;
    }

    system("cls");
    printf("LUCRO TOTAL: R$ %.2f", lucro);

    printf("\n\n\n[Lista de lucro por produto]\n");

    float custo_total, valor_total_vendido, lucro_do_produto;
    for(int i=0; i<quantidade_produtos; i++) {
        custo_total = produtos[i].valor_bruto * produtos[i].quantidades_vendidas;
        valor_total_vendido = produtos[i].valor_produto * produtos[i].quantidades_vendidas;
        lucro_do_produto = valor_total_vendido - custo_total;

        printf("\nNome do produto: %s ", produtos[i].nome);
        printf("\n  Custo total: R$ %.2f", custo_total);
        printf("\n  Total vendido: R$ %.2f", valor_total_vendido);
        printf("\n  Lucro do produto: R$ %.2f\n", lucro_do_produto);
    }

    return 0;
}
