#include <stdio.h>

int main(){
    float valor_produto;
    float valor_cliente;

    do{
        printf("Digite o preco do produto: ");
        scanf("%f", &valor_produto);
        if(valor_produto < 0.00)
            printf("\n[ERRO] O valor deve ser positivo!\n");
    }while(valor_produto < 0.00);
    system("cls");

    do{
        printf("Digite a quantia de dinheiro do cliente: ");
        scanf("%f", &valor_cliente);
        if(valor_produto > valor_cliente)
            printf("\nEsta faltando %.1f\n", valor_produto - valor_cliente);
    }while(valor_produto > valor_cliente);
    system("cls");

    printf("******************Troco******************\n");
    printf("%.2f - %.2f = %f\n\n", valor_cliente, valor_produto, valor_cliente - valor_produto);


    if(valor_produto < valor_cliente){
        float troco = valor_cliente - valor_produto;
        int notas;

        if(troco / 200 >= 1.0){
            notas = troco / 200.0;
            troco = troco - 200.0 * notas;
            printf("200.00 = %d\n", notas);
        }
        if(troco / 100 >= 1.0){
            notas = troco / 100.0;
            troco = troco - 100.0 * notas;
            printf("100.00 = %d\n", notas);
        }
        if(troco / 50 >= 1.0){
            notas = troco / 50.0;
            troco = troco - 50.0 * notas;
            printf("50.00 = %d\n", notas);
        }
        if(troco / 20 >= 1.0){
            notas = troco / 20.0;
            troco = troco - 20.0 * notas;
            printf("20.00 = %d\n", notas);
        }
        if(troco / 10 >= 1.0){
            notas = troco / 10.0;
            troco = troco - 10.0 * notas;
            printf("10.00 = %d\n", notas);
        }
        if(troco / 5 >= 1.0){
            notas = troco / 5.0;
            troco = troco - 5.0 * notas;
            printf("5.00 = %d\n", notas);
        }
        if(troco / 2 >= 1.0){
            notas = troco / 2.0;
            troco = troco - 2.0 * notas;
            printf("2.00 = %d\n", notas);
        }
        if(troco / 1 >= 1.0){
            notas = troco / 1.0;
            troco = troco - 1.0 * notas;
            printf("1.00 = %d\n", notas);
        }
        if(troco / 0.5 >= 1.0){
            notas = troco / 0.5;
            troco = troco - 0.5 * notas;
            printf("0.50 = %d\n", notas);
        }
        if(troco / 0.25 >= 1.0){
            notas = troco / 0.25;
            troco = troco - 0.25 * notas;
            printf("0.25 = %d\n", notas);
        }
        if(troco / 0.10 >= 1.0){
            notas = troco / 0.10;
            troco = troco - 0.10 * notas;
            printf("0.10 = %d\n", notas);
        }
        if(troco / 0.05 >= 1.0){
            notas = troco / 0.05;
            troco = troco - 0.05 * notas;
            printf("0.05 = %d\n", notas);
        }
        if(troco / 0.01 >= 1.0){
            notas = troco / 0.01;
            troco = troco - 0.01 * notas;
            printf("0.01 = %d\n", notas);
        }
        printf("\n\n");
    }
    return 0;
}