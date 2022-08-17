#include <stdio.h>
#include <time.h>

#define TAM 5

int main(){

    char string[TAM];
    char vogais[TAM];
    int i, j, falhou;
    char troca;
    int posicao[TAM];

    srand(time(NULL));

    for(i = 0; i < TAM; i++)
        posicao[i] = -1;

    i = 0;
    do{
        falhou = 0;
        string[i] = 65 + rand() % 57;
        for(j = 0; j < i; j++){
            if(string[i] == string[j])
                falhou = 1;
        }
        if(string[i] > 90 && string[i] < 97)
            falhou = 1;
        if(falhou == 0)
            i++;
    } while (i < TAM);

    printf("\nString original: ");
    for(i = 0; i < TAM; i++)
        printf("%c ", string[i]);


    printf("\n\nString vogais: ");
    for(i = 0; i < TAM; i++)
        if(string[i] == 65 || string[i] == 69 || string[i] == 73 || string[i] == 79 || string[i] == 85 || string[i] == 97 || string[i] == 101 || string[i] == 105 || string[i] == 111 || string[i] == 117){
            printf("%c ", string[i]);
        }

    for(i = 0; i < TAM; i++){
        for(j = 0; j < i; j++){
            if(string[j] > string[i]){
                troca = string[j];
                string[j] = string[i];
                string[i] = troca;
            }
        }
    }
    
    for(i = 0; i < TAM; i++){
        if(string[i] == 65 || string[i] == 69 || string[i] == 73 || string[i] == 79 || string[i] == 85 || string[i] == 97 || string[i] == 101 || string[i] == 105 || string[i] == 111 || string[i] == 117){
            posicao[i] = i;
        }
    }

    j = 0;
    for(i = 0; i < TAM; i++){
        if(posicao[i] != -1){
            if(j == 0){
                vogais[j] = string[posicao[i]];
                j++;
            }
            else{
                vogais[j] = string[posicao[i]];
                j++;
            }
        }
    }

    vogais[j] = '\0';

    for(i = 0; vogais[i] != '\0'; i++){
        for(j = 0; j < i; j++){
            if(vogais[j] != 65 && vogais[i] == 97){
                troca = vogais[j];
                vogais[j] = vogais[i];
                vogais[i] = troca;
            }
            else if(vogais[j] != 65 && vogais[j] != 97 && vogais[j] != 69 && vogais[i] == 101){
                troca = vogais[j];
                vogais[j] = vogais[i];
                vogais[i] = troca;
            }
            else if(vogais[j] != 65 && vogais[j] != 97 && vogais[j] != 69 && vogais[j] != 101 && vogais[j] != 73 && vogais[i] == 105){
                troca = vogais[j];
                vogais[j] = vogais[i];
                vogais[i] = troca;
            }
            else if(vogais[j] != 65 && vogais[j] != 97 && vogais[j] != 69 && vogais[j] != 101 && vogais[j] != 73 && vogais[j] != 105 && vogais[j] != 79 && vogais[i] == 111){
                troca = vogais[j];
                vogais[j] = vogais[i];
                vogais[i] = troca;
            }
        }
    }

    printf("\n\nString vogais ordenadas: ");
    for(i = 0; vogais[i] != '\0'; i++)
        printf("%c ", vogais[i]);

    printf("\n\n");
    

    return 0;
}