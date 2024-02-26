#include <stdio.h>

#define NOTAS {200, 100, 50, 20, 10, 5, 2}
#define MOEDAS {50, 25, 10, 5, 1}

#define NUM_NOTAS 8
#define NUM_MOEDAS 5

void calcularTroco(float troco) {
    int notas[NUM_NOTAS] = NOTAS;
    int moedas[NUM_MOEDAS] = MOEDAS;

    printf("******************Troco******************\n");

    int i;
    for (i = 0; i < NUM_NOTAS; i++) {
        int quantidade = troco / notas[i];
        troco -= quantidade * notas[i];
        if (quantidade > 0)
            printf("%.2f = %d\n", (float)notas[i], quantidade);
    }

    troco *= 100;
    for (i = 0; i < NUM_MOEDAS; i++) {
        int quantidade = troco / moedas[i];
        troco -= quantidade * moedas[i];
        if (quantidade > 0)
            printf("%.2f = %d\n", (float)moedas[i] / 100, quantidade);
    }

    printf("\n\n");
}

int main() {
    float valor_produto;
    float valor_cliente;

    do {
        printf("Digite o preco do produto: ");
        scanf("%f", &valor_produto);
        if (valor_produto < 0.00)
            printf("\n[ERRO] O valor deve ser positivo!\n");
    } while (valor_produto < 0.00);

    do {
        printf("Digite a quantia de dinheiro do cliente: ");
        scanf("%f", &valor_cliente);
        if (valor_produto > valor_cliente)
            printf("\nEsta faltando %.1f\n", valor_produto - valor_cliente);
    } while (valor_produto > valor_cliente);

    printf("******************Troco******************\n");
    printf("%.2f - %.2f = %.2f\n\n", valor_cliente, valor_produto, valor_cliente - valor_produto);

    if (valor_produto < valor_cliente) 
        calcularTroco(valor_cliente - valor_produto);

    return 0;
}