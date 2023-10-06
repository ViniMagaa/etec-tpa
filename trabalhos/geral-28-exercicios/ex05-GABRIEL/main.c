#include <stdio.h>
#include <locale.h>

int main() {

setlocale(LC_ALL, "Portuguese");

    float preco_unitario, valor_pago;
    int quantidade;
    float total, troco;

    printf("Insira o preço do produto: ");
    scanf("%f", &preco_unitario);

    printf("Insira a quantidade de unidades compradas: ");
    scanf("%d", &quantidade);

    printf("Insira o valor em dinheiro dado pelo cliente: ");
    scanf("%f", &valor_pago);

    // calculo
    total = preco_unitario * quantidade;

    // verificar se tem saldo
    if (valor_pago >= total) {
        // calculo troco
        troco = valor_pago - total;

        // troco
        printf("Troco a ser devolvido: R$ %.2f\n", troco);
    } else {
        printf("Saldo insuficiente. Valor faltante: R$ %.2f\n", total - valor_pago);
    }

    return 0;
}
