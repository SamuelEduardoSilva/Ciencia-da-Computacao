//Feito por Samuel Eduardo da Silva
#include<stdio.h>

main(){
   int i,NA;
   float nota,media,soma=0;
   scanf("%i",&NA);
   for (i=0;i<NA;i++){
    scanf("%f",&nota);
    soma=soma+nota;
   }
   media=soma/NA;
   printf("A media aritmetica eh = %.2f\n",media);
}
