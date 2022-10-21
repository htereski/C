#include <stdio.h>
#include <ctype.h>
#define TAM 50

typedef struct{
    char nome[TAM];
    char nome_bibliografico[TAM];
}Pessoa;

Pessoa usuario;

void preencherNome(){
    system("cls");
    printf("Digite seu nome: ");
    fflush(stdin);
    gets(usuario.nome);
}

int encontrarUltimoEspaco(){
    int i;
    int espaco = 0;
    for(i = 0; usuario.nome[i] != '\0'; i++){
        if(usuario.nome[i] == ' '){
            espaco = i;
        }
    }
    return espaco;
}

int nomeTemSobrenome(){
    int j;
    for(j = 0; usuario.nome[j] != '\0'; j++){
        if(usuario.nome[j] == ' ' && usuario.nome[j+1] != '\0'){
            return 1;
        }
    }
    return 0;
}

void referenciaBibliografica(){
    int i;
    int j = 0;
    int espaco;

    preencherNome();
    espaco = encontrarUltimoEspaco();

    if(nomeTemSobrenome()){
        for(i = 0; usuario.nome[i] != '\0'; i++){
            if(usuario.nome[espaco+i+1] != '\0'){
                usuario.nome_bibliografico[j] = usuario.nome[espaco+i+1];
                j++;
            }
            else{
                break;
            }
        }
        usuario.nome_bibliografico[j] = ' ';
        j++;

        for(i = 0; i < espaco; i++){
            if(usuario.nome[i] == ' '){
                usuario.nome_bibliografico[j] = usuario.nome[i+1];
                usuario.nome_bibliografico[j+1] = '.';
                usuario.nome_bibliografico[j+2] = ' ';
                j += 3;
            }
        }

        for(i = 0; usuario.nome[i] != ' '; i++){
            usuario.nome_bibliografico[j] = usuario.nome[i];
            j++;
        }
    }
    else{
        for(i = 0; usuario.nome[i] != '\0'; i++){
            usuario.nome_bibliografico[j] = usuario.nome[i];
            j++;
        }
    }
}

void maiusculo(){
    int i;
    usuario.nome_bibliografico[0] = toupper(usuario.nome_bibliografico[0]);
    for(i = 1; usuario.nome_bibliografico[i] != '\0'; i++){
        if(usuario.nome_bibliografico[i] == ' '){
            usuario.nome_bibliografico[i+1] = toupper(usuario.nome_bibliografico[i+1]);
        }
    }
}

void minusculo(){
    int i;
    for(i = 1; usuario.nome_bibliografico[i] != '\0'; i++){
        if(usuario.nome_bibliografico[i] != ' '){
            usuario.nome_bibliografico[i] = tolower(usuario.nome_bibliografico[i]);
        }
    }

}

void imprimirReferencia(){
    printf("\n-------------------------\n");
    printf("%s", usuario.nome_bibliografico);
    printf("\n-------------------------\n\n");
}

void criar(){

    referenciaBibliografica();
    maiusculo();
    minusculo();
    imprimirReferencia();
}

int main(){

    criar();

    return;
}