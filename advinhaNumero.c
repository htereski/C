#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

    int numero = 0;
    int gerado;
    int max = 99, min = 1;
    int cont = 1;
    int aux;

    srand(time(NULL));

    printf("\n----Advinhe o numero gerado pelo computador----\n\n");

    //valor aleatório gerado pelo computador
    gerado = (rand() % 98) + 1;

    //printf("\n%d\n", gerado);
    while (numero != gerado)
    {

        printf("Tentativa [%d]: o numero esta entre %d e %d \n", cont, min, max);
        scanf("%d", &numero);

        aux = 0;

        //Verifica se está dentro da faixa de valores
        while((numero < 1) || (numero > 99)){
            printf("Digite um numero VALIDO!\n");
            printf("Tentativa [%d]: o numero esta entre %d e %d \n", cont, min, max);
            scanf("%d", &numero);
            if((numero > 0) && (numero < 100)){
                cont++;
                aux = 1;
            }
        }

        if((numero > min) && (numero <= gerado)){
            min = numero;
        }
        else if((numero < max) && (numero >= gerado)){
            max = numero;
        }

        
        if(cont > 10){
            gerado = numero;
        }

        if(numero != gerado){
            if(aux == 0){
                cont++;
            }
        } 
    }

    if(cont < 11){
        printf("\nResposta certa com [%d] tentativas :)\n\n", cont);
    }
    else{
        printf("\nVoce excedeu o numero de tentativas :(\n\n");
    }
    
    return 0;
}