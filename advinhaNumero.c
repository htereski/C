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

int validaJogada(int num_jogador, int num, int *min, int *max){
    if(num_jogador < num)
        *min = num_jogador;
    else
        *max = num_jogador;
}

void status(int ok, int chance){
    if(ok == 1)
        printf("PARABENS! Voce venceu com %d tentativas!!!\n\n", chance);
    else
        printf("VOCE PERDEU! Mais sorte da proxima vez!!!\n\n");
}

int fimJogo(int chance, int num, int num_jogador){
    if(chance < 11){
        if(num == num_jogador){
            return 1;
        }
    }
    return 0;
}

int jogada(){
    int min = 1, max = 99;
    int chance = 1;
    int num_jogador;
    int numero = criarNumero();
    int ok = 0;
    do{
        num_jogador = entradaJogador(chance, min, max);
        validaJogada(num_jogador, numero, &min, &max);
        if(num_jogador != numero)
            chance++;
        else
            ok = 1;
    }while(fimJogo(chance, numero, num_jogador) == 0);
    status(ok, chance);
}

int main(){
    jogada();
    return;
}