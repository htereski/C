#include <stdio.h>
#include <time.h>

int criarNumero(){
    srand(time(NULL));
    int numero = 1 + rand() % 98;
    return numero;    
}

int validaEntrada(int num, int min, int max){
    if(num < 1 || num > 99 || num <= min || num >= max)
        return 0;
    return 1;
}

int entradaJogador(int i, int min, int max){
    int num;
    int valida;

    do{
        printf("Tentativa [%d] Digite um numero entre %2d e %2d: ", i, min, max);
        scanf("%d", &num);
        valida = validaEntrada(num, min, max);
        if(valida == 0)
            printf("[ERRO] Digite um numero valido!!!\n");
    }while(valida == 0);

    return num;
}

int validaJogada(int numJogador, int num, int *min, int *max){
    if(numJogador < num)
        *min = numJogador;
    else
        *max = numJogador;
}

void status(int ok, int chance){
    if(ok == 1)
        printf("PARABENS Voce venceu com %d tentativas!!!\n\n", chance);
    else
        printf("VOCE PERDEU mais sorte da proxima vez!!!\n\n");
}

int fimJogo(int chance, int num, int numJogador){
    if(chance < 11){
        if(num == numJogador){
            return 1;
        }
    }
    return 0;
}

int jogada(){
    int min = 1, max = 99;
    int chance = 1;
    int numJogador;
    int numero = criarNumero();
    int ok = 0;

    do{
        numJogador = entradaJogador(chance, min, max);
        validaJogada(numJogador, numero, &min, &max);
        if(numJogador != numero)
            chance++;
        else
            ok = 1;
    }while(fimJogo(chance, numero, numJogador) == 0);

    status(ok, chance);
}

int main(){
    jogada();
    return;
}