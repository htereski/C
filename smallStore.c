#include <stdio.h>
#define TAM 10

int main(){

    float valor_obj[TAM];
    int qtd_vendas[TAM] = {0};
    int i = 0;
    int posicao, continuar = 1, valor;
    float total_vendas = 0;
    float comissao = 0;
    int mais_vendido = 0;

    printf("Armaze os precos\n\n");
    while(i < TAM){
        printf("preco %d: ", i+1);
        scanf("%f", &valor_obj[i]);
        if(valor_obj[i] > 0.00)
            i++;
        else
            printf("[Erro] O preco deve ser maior que R$ 0.00\n\n");
    }
    while(continuar == 1){
        i = 0;
        while(i < 1){
            printf("Digite a posicao do produto que foi vendida: ");
            scanf("%d", &posicao);
            posicao = posicao-1;
            if(posicao < 0 || posicao > 10){
                printf("[ERRO] Posicao inexistente!\n\n");
                system("pause");
                system("cls");
            }
            else{
                printf("Digite a quantidade de vendas: ");
                scanf("%d", &valor);
                if(valor < 0){
                    printf("[Erro] O valor deve ser positivo!\n\n");
                    system("pause");
                    system("cls");
                }
                else{
                    qtd_vendas[posicao] = qtd_vendas[posicao] + valor;
                    total_vendas += qtd_vendas[posicao] * valor_obj[posicao];
                    i++;
                }
            }
        }

        do{
            printf("Deseja acrescentar mais vendas? [SIM-1] [NAO-0]\n");
            scanf("%d", &continuar);
            if(continuar != 0 && continuar != 1){
                printf("[Erro] Digite uma opcao valida!\n\n");
                system("pause");
                system("cls");
            }
        }while(continuar != 0 && continuar != 1);
    };

    for(i = 0; i < TAM; i++){
        printf("Valor Unitario: %.2f\tVendido %d\tValor total %.2f\n", valor_obj[i], qtd_vendas[i], valor_obj[i] * qtd_vendas[i]);
    }

    comissao = total_vendas * 5 / 100;

    printf("\n\nTotal gerado em vendas: %.2f\n", total_vendas);
    printf("Comissao de: %.2f\n\n\n", comissao);

    for(i = 0; i < TAM; i++){
        if(qtd_vendas[i] > mais_vendido)
            mais_vendido = qtd_vendas[i];
    }

    for(i = 0; i < TAM; i++){
        if(mais_vendido == qtd_vendas[i])
            printf("Mais Vendido\n\nPosicao: %d\tQuantidade: %d\n", i+1, mais_vendido);
    }

    return 0;
}