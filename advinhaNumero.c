#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

    int numero = 0;
    int gerado;
    int max = 99, min = 1;
    int cont = 1;

    srand(time(NULL));

    printf("\n----Advinhe o numero gerado pelo computador----\n\n");

    //valor aleatório gerado pelo computador
    gerado = (rand() % 98) + 1;

    //printf("\n%d\n", gerado);
    while (numero != gerado)
    {

        printf("Tentativa [%d]: o numero esta entre %d e %d \n", cont, min, max);
        scanf("%d", &numero);

        //Verifica se está dentro da faixa de valores
        while((numero < 1) || (numero > 99)){
            printf("Digite um numero VALIDO!\n");
            printf("Tentativa [%d]: o numero esta entre %d e %d \n", cont, min, max);
            scanf("%d", &numero);
        }

        if((numero > min) && (numero <= gerado)){
            min = numero;
        }
        else if((numero < max) && (numero >= gerado)){
            max = numero;
        }

        if(numero != gerado){
            cont++;
        }

        //Validações de parada
        if(cont > 10){
            gerado = numero;
        }

        if(cont == 11){
            gerado = numero;
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