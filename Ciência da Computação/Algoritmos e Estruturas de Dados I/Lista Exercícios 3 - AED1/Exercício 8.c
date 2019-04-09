//Feito por Samuel Eduardo da Silva
#include<stdio.h>

main(){
    int N1,N2,i,soma=0;
    printf("Digite um numero:\n");
    scanf("%i",&N1);
    printf("Digite o segundo numero:\n");
    scanf("%i",&N2);
    for (i=N1+1;i<N2;i++){
        if (i%2==0){
            printf("%i\n",i);
            soma=soma+i;
        }

    }
    printf("A soma desses numeros pares eh: %i",soma);
}
