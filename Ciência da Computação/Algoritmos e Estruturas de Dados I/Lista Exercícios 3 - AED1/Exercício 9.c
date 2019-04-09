//Feito por Samuel Eduardo da Silva
#include<stdio.h>

main(){
   float i,H=0,N;
   printf("Digite um numero para N:\n");
   scanf("%f",&N);
   for (i=1;i<=N;i++){
    H=H+(1.0/i);
   }
   printf("O numero H eh : %.2f",H);
}
