#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

typedef struct{
    char *String;
    char *Vogais;
}Palavra;

Palavra *elemento;

void gerarString();
void stringVogais();
void ordenarString();
void atribuirVogais();
void ordenarVogais();

int main(){  
    gerarString();
    stringVogais();
    ordenarString();
    atribuirVogais();
    ordenarVogais();
    return 0;
}

void gerarString(){
    srand(time(NULL));
    int i = 0, j;
    int falhou;
    elemento = malloc(sizeof(Palavra));
    elemento->String = malloc(TAM * sizeof(char));
    while(i < TAM){
        falhou = 0;
        elemento->String[i] = 65 + rand() % 57;
        for(j = 0; j < i; j++){
            if(elemento->String[i] == elemento->String[j]){
                falhou = 1;
                break;
            }
        }
        if(elemento->String[i] > 90 && elemento->String[i] < 97)
            falhou = 1;
        if(falhou == 0)
            i++;
    };
    elemento->String[i] = '\0';
    printf("\nString original: %s", elemento->String);
}

void stringVogais(){
    int i;
    printf("\n\nString vogais: ");
    for(i = 0; i < TAM; i++)
        if(elemento->String[i] == 65 || elemento->String[i] == 69 || elemento->String[i] == 73 || elemento->String[i] == 79 || elemento->String[i] == 85 || elemento->String[i] == 97 || elemento->String[i] == 101 || elemento->String[i] == 105 || elemento->String[i] == 111 || elemento->String[i] == 117)
            printf("%c ", elemento->String[i]);
}

void ordenarString(){
    int i, j, troca;
    for(i = 0; i < TAM; i++){
        for(j = 0; j < i; j++){
            if(elemento->String[j] > elemento->String[i]){
                troca = elemento->String[j];
                elemento->String[j] = elemento->String[i];
                elemento->String[i] = troca;
            }
        }
    }
}

void atribuirVogais(){
    int i, j, posicao[TAM];
    int tam = 0;
    for(i = 0; i < TAM; i++)
        posicao[i] = -1;
    
    for(i = 0; i < TAM; i++){
        if(elemento->String[i] == 65 || elemento->String[i] == 69 || elemento->String[i] == 73 || elemento->String[i] == 79 || elemento->String[i] == 85 || elemento->String[i] == 97 || elemento->String[i] == 101 || elemento->String[i] == 105 || elemento->String[i] == 111 || elemento->String[i] == 117){
            posicao[i] = i;
            tam++;
        }
    }
    j = 0;
    elemento->Vogais = malloc(tam * sizeof(char));
    for(i = 0; i < TAM; i++){
        if(posicao[i] != -1){
            elemento->Vogais[j] = elemento->String[posicao[i]];
            j++;
        }
    }
    elemento->Vogais[j] = '\0';
}

void ordenarVogais(){
    int i, j;
    char troca;
    for(i = 0; elemento->Vogais[i] != '\0'; i++){
        for(j = 0; j < i; j++){
            if(elemento->Vogais[j] != 65 && elemento->Vogais[i] == 97){
                troca = elemento->Vogais[j];
                elemento->Vogais[j] = elemento->Vogais[i];
                elemento->Vogais[i] = troca;
            }
            else if(elemento->Vogais[j] != 65 && elemento->Vogais[j] != 97 && elemento->Vogais[j] != 69 && elemento->Vogais[i] == 101){
                troca = elemento->Vogais[j];
                elemento->Vogais[j] = elemento->Vogais[i];
                elemento->Vogais[i] = troca;
            }
            else if(elemento->Vogais[j] != 65 && elemento->Vogais[j] != 97 && elemento->Vogais[j] != 69 && elemento->Vogais[j] != 101 && elemento->Vogais[j] != 73 && elemento->Vogais[i] == 105){
                troca = elemento->Vogais[j];
                elemento->Vogais[j] = elemento->Vogais[i];
                elemento->Vogais[i] = troca;
            }
            else if(elemento->Vogais[j] != 65 && elemento->Vogais[j] != 97 && elemento->Vogais[j] != 69 && elemento->Vogais[j] != 101 && elemento->Vogais[j] != 73 && elemento->Vogais[j] != 105 && elemento->Vogais[j] != 79 && elemento->Vogais[i] == 111){
                troca = elemento->Vogais[j];
                elemento->Vogais[j] = elemento->Vogais[i];
                elemento->Vogais[i] = troca;
            }
        }
    }
    printf("\n\nString vogais ordenadas: ");
    for(i = 0; elemento->Vogais[i] != '\0'; i++)
        printf("%c ", elemento->Vogais[i]);
    printf("\n\n");
}