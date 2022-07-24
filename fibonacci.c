#include <stdio.h>

int main(){

    int num, i;
    int pre = 0, next = 0, current = 1;

    do
    {
        printf("Digite um valor MAXIMO para a sequencia de Fibonacci: ");
        scanf("%d", &num);
        if(num < 1){
            printf("\n[ERRO] Digite um numero maior que Zero!\n\n");
        }
    } while (num < 1);

    printf("1 ");
    for(i = 0; i < num-1; i++){
        next = current + pre;
        printf("%d ", next);
        pre = current;
        current = next;
    }

    printf("\n\n");

    return 0;
}