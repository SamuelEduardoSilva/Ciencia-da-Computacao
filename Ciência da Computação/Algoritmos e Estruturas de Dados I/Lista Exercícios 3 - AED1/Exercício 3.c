//Feito por Samuel Eduardo da Silva
#include<stdio.h>

main(){
  int i;
  float soma=0;
  for (i=1;i<=100;i++){
    printf("%i\n",i);
    soma=soma+(i/2.0);
  }

    printf("Soma = %.2f\n",soma);
}
