#include <stdio.h>

#define TAM 10

int main(){

    float valor_obj[TAM];
    int qtd_vendas[TAM] = {0};
    int i, cont;
    int posicao, continuar, valor;
    float total_vendas = 0;
    float comissao = 0;
    int mais_vendido = 0;
    int ok;


    printf("Armaze os precos\n\n");
    for(i = 0; i < TAM; i++){
        printf("preco %d: ", i+1);
        scanf("%f", &valor_obj[i]);
        if(valor_obj[i] <= 0.00){
            i--;
        }
    }

    do{
        cont = 1;
        for(i = 0; i < cont; i++){
            printf("Digite a posicao do produto que foi vendida: ");
            scanf("%d", &posicao);
            posicao = posicao-1;

            if(posicao < 0 || posicao > 10){
                printf("[ERRO] Posicao inexistente!\n\n");
                i--;
            }
            else{
                printf("Digite a quantidade de vendas: ");
                scanf("%d", &valor);
                qtd_vendas[posicao] = qtd_vendas[posicao] + valor;
                total_vendas += qtd_vendas[posicao] * valor_obj[posicao];
            }
        }

        do{
            printf("Deseja acrescentar mais vendas? [SIM-1] [NAO-0]\n");
            scanf("%d", &continuar);
            if(continuar == 0 || continuar == 1)
                ok = 1;
            else
                ok = 0;
        }while(ok != 1);
    }while(continuar == 1);

    for(i = 0; i < TAM; i++){
        printf("Valor Unitario: %.2f\tVendido %d\tValor total %.2f\n", valor_obj[i], qtd_vendas[i], valor_obj[i] * qtd_vendas[i]);
    }

    comissao = total_vendas * 5 / 100;

    printf("\n\nTotal gerado em vendas: %.2f\n", total_vendas);
    printf("Comissao de: %.2f\n\n", comissao);

    for(i = 0; i < TAM; i++){
        if(qtd_vendas[i] > mais_vendido){
            mais_vendido = qtd_vendas[i];
        }
    }

    for(i = 0; i < TAM; i++){
        if(mais_vendido == qtd_vendas[i]){
            printf("Posicao: %d\tValor: %d\n", i+1, mais_vendido);
        }
    }
    

    return 0;
}