#include <stdio.h>
#include <time.h>

#define TAM 5

int main(){

    char string[TAM];
    int i, j, falhou;
    char troca;

    srand(time(NULL));

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

    printf("\n\nString vogais orrdenadas: ");
    for(i = 0; i < TAM; i++){
        if(string[i] == 65 || string[i] == 69 || string[i] == 73 || string[i] == 79 || string[i] == 85 || string[i] == 97 || string[i] == 101 || string[i] == 105 || string[i] == 111 || string[i] == 117){
            printf("%c ", string[i]);
        }
    }
    printf("\n\n");
    

    return 0;
}