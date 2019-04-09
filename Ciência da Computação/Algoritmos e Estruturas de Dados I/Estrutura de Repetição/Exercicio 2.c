#include<stdio.h>

main(){
   int cont;
   float nota,soma=0,media;
   for (cont=0;cont<10;cont++){
    printf("Digite uma das nota:\n");
    scanf("%f",&nota);
    soma=soma+nota;

   }
   media=soma/10;
   printf("A media aritmetica eh: %.2f",media);
}
