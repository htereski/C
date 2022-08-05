#include <stdio.h>

#define TAM 100

int main(){

    char nome_entrada[TAM];
    char nome_referencia[TAM];
    int posicao[TAM];
    int i = 0;
    int j = 0;
    int k = 0;
    int cont = 0;
    int primeiro = 100, ultimo = 0;
    int qtd_nome = 0, qtd_sobre = 0;

    printf("\nDigite seu nome completo: ");
    gets(nome_entrada);
    
    for(i = 0; i < TAM; i++){
        posicao[i] = -1;
    }

    for(i = 0; nome_entrada[i] != '\0'; i++){
        if(nome_entrada[i] == ' '){
            posicao[i] = i;
        }
        k++;
    }

    for(i = 0; nome_entrada[i] != '\0'; i++){
        if(posicao[i] != -1){
            if(posicao[i] > ultimo){
                ultimo = posicao[i];
            }
            if(posicao[i] < primeiro){
                primeiro = posicao[i];
            }
        }
    }

    for(i = 0; nome_entrada[i] != '\0'; i++){
        if(i > ultimo){
            qtd_sobre++;
        }
        if(i < primeiro){
            qtd_nome++;
        }
    }

    for(i = 0; nome_entrada[i] != '\0'; i++){
        if(i < qtd_sobre){
            nome_referencia[cont] = nome_entrada[ultimo+1+i];
            cont++;
        }
        if(i == qtd_sobre){
            i = k;
        }
    }

    nome_referencia[cont] = ' ';
    cont++;

    for(i = 0; nome_entrada[i] != '\0'; i++){
        if(i < qtd_nome){
            nome_referencia[cont] = nome_entrada[j+i];
            cont++;
        }
        if(i == qtd_nome){
            i = k;
        }
    }

    nome_entrada[cont] = '\0';

    printf("\nSeu nome em referencia bibliografica %s\n\n", nome_referencia);

    return 0;
}