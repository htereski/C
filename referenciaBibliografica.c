#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 100

typedef struct{
    char *nome;
    char *nome_bibliografico;
}Pessoa;

Pessoa *usuario;

int validarEntradaNome(char nome[]);
void preencherNome();
int encontrarUltimoEspaco();
int nomeTemSobrenome(int espaco);
void referenciaBibliografica();
void maiusculo();
void minusculo();
void imprimirReferencia();
void criar();

int main(){
    criar();
    return;
}

int validarEntradaNome(char nome[]){
    int i;
    for(i = 0; nome[i] != '\0'; i++){
        if(nome[i] != ' ')
            return 1;
    }
    return 0;
}

void preencherNome(){
    char aux[TAM];
    system("cls");
    do{
        printf("Digite seu nome: ");
        fflush(stdin);
        gets(aux);
        if(validarEntradaNome(aux) == 0){
            printf("[Erro] Nao deixe o campo em branco!\n\n");
            system("pause");
            system("cls");
        }
    }while(validarEntradaNome(aux) == 0);
    usuario = malloc(sizeof(Pessoa));
    usuario->nome = malloc(strlen(aux) * sizeof(char));
    strcpy(usuario->nome, aux);
}

int encontrarUltimoEspaco(){
    int i;
    int espaco = 0;
    for(i = 0; usuario->nome[i] != '\0'; i++){
        if(usuario->nome[i] == ' '){
            espaco = i;
        }
    }
    return espaco;
}

int nomeTemSobrenome(int espaco){
    int i;
    if(espaco != 0){
        for(i = espaco; usuario->nome[i] != '\0'; i++){
            if(usuario->nome[i] != ' ')
                return 1;
        }
    }
    return 0;
}

void referenciaBibliografica(){
    int i;
    int j = 0;
    int espaco;
    char aux[TAM];

    preencherNome();
    espaco = encontrarUltimoEspaco();

    if(nomeTemSobrenome(espaco)){
        for(i = 0; usuario->nome[i] != '\0'; i++){
            if(usuario->nome[espaco+i+1] != '\0'){
                aux[j] = usuario->nome[espaco+i+1];
                j++;
            }
            else{
                break;
            }
        }
        aux[j] = ' ';
        j++;

        for(i = 0; i < espaco; i++){
            if(usuario->nome[i] == ' '){
                aux[j] = usuario->nome[i+1];
                aux[j+1] = '.';
                aux[j+2] = ' ';
                j += 3;
            }
        }

        for(i = 0; usuario->nome[i] != ' '; i++){
            aux[j] = usuario->nome[i];
            j++;
        }
    }
    else{
        for(i = 0; usuario->nome[i] != '\0'; i++){
            aux[j] = usuario->nome[i];
            j++;
        }
    }
    usuario->nome_bibliografico = malloc(strlen(aux) * sizeof(char));
    strcpy(usuario->nome_bibliografico, aux);
}

void maiusculo(){
    int i;
    usuario->nome_bibliografico[0] = toupper(usuario->nome_bibliografico[0]);
    for(i = 1; usuario->nome_bibliografico[i] != '\0'; i++){
        if(usuario->nome_bibliografico[i] == ' '){
            usuario->nome_bibliografico[i+1] = toupper(usuario->nome_bibliografico[i+1]);
        }
    }
}

void minusculo(){
    int i;
    for(i = 1; usuario->nome_bibliografico[i] != '\0'; i++){
        if(usuario->nome_bibliografico[i] != ' '){
            usuario->nome_bibliografico[i] = tolower(usuario->nome_bibliografico[i]);
        }
    }

}

void imprimirReferencia(){
    printf("\n-------------------------\n");
    printf("%s", usuario->nome_bibliografico);
    printf("\n-------------------------\n\n");
}

void criar(){
    referenciaBibliografica();
    minusculo();
    maiusculo();
    imprimirReferencia();
}