#include <stdio.h>
#include <stdlib.h>

struct vendas
{
    char produto[20];
    int quantidade;
    float preco;
};

int main()
{
    struct vendas vendas1;

    strcpy(vendas1.produto, "Bolos");
    vendas1.quantidade = 10;
    vendas1.preco = 2.50;

    struct vendas vendas2;

    strcpy(vendas2.produto, "Pasteis");
    vendas2.quantidade = 20;
    vendas2.preco = 5.00;

    printf("Bem vindo a feira da Clotilde!\n\n");
    printf("===================================================\n\n");
    printf("Produto: %s\n", vendas1.produto);
    printf("Quantidade: %d %s\n", vendas1.quantidade, vendas1.produto);
    printf("Preco: R$ %.2f\n\n", vendas1.preco);
    printf("===================================================\n\n");
    printf("Produto: %s\n", vendas2.produto);
    printf("Quantidade: %d %s\n", vendas2.quantidade, vendas1.produto);
    printf("Preco: R$ %.2f\n\n", vendas2.preco);

    return 0;
}
