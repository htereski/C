#include <stdio.h>

#define TAM 100

int main(){

    int deseja;
    
    do{
        printf("\n*****************************");
        printf("\nDeseja cadastrar um nome?");
        printf("\n-1 SIM");
        printf("\n-2 NAO");
        printf("\n*****************************\n");
        scanf("%d", &deseja);

        if(deseja < 1 || deseja > 2)
            printf("\n[ERRO] Digite uma opcao valida!");
    }while(deseja < 1 || deseja > 2);
    system("cls");

    if(deseja == 1){
        do{
            printf("Quantos nomes voce deseja cadastrar?\n");
            scanf("%d", &deseja);
            system("cls");

            if(deseja < 1)
                printf("Digite um numero maior que ZERO!\n");
        }while(deseja < 1);
        system("cls");

        char nomes[deseja][TAM];
        char referencia[deseja][TAM];
        int maior[deseja][1];
        int i, j, k;

        for(i = 0; i < deseja; i++){
            fflush(stdin);
            printf("Digite o nome %d: ", i+1);
            gets(nomes[i]);
        }
        system("cls");


        for(i = 0; i < deseja; i++)
            maior[i][0] = -1;
        

        for(i = 0; i < deseja; i++){
            for(j = 0; nomes[i][j] != '\0'; j++){
                if(nomes[i][j] == ' '){
                    maior[i][0] = j;
                }
            }
        }

        for(i = 0; i < deseja; i++){
            k = 0;
            for(j = maior[i][0]; nomes[i][j] != '\0'; j++){
                referencia[i][k] = nomes[i][j];
                k++;
            }

            referencia[i][k] = ' ';
            k++;

            for(j = 0; j < maior[i][0]-1; j++){
                if(nomes[i][j] == ' '){
                    referencia[i][k] = nomes[i][j+1];
                    referencia[i][k+1] = '.';
                    k += 2;
                    referencia[i][k] = ' ';
                    k++;
                }
            }


            for(j = 0; nomes[i][j] != ' '; j++){
                referencia[i][k] = nomes[i][j];
                k++;
            }
            referencia[i][k] = '\0';
        }
        

        if(deseja == 1){
            printf("O nome em referencia bibliografica\n\n");
        }
        else{
            printf("Os nomes em referencia bibliografica\n\n");
        }
        for(i = 0; i < deseja; i++){
            printf("%s\n", referencia[i]);
        }
        printf("\n\n");
    }   
    else{
        system("cls");
    }
    
    return 0;
}