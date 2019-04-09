#include<stdio.h>

main(){
  int cont;
  float soma=0,valor,M;
  for (cont=0;cont<5;cont++){
    printf("Digite um valor:\n",valor);
    scanf("%f",&valor);
    soma=soma+valor;
  }
  M=soma/5;
  printf("A soma eh:%.2f\n",soma);
  printf("A media eh:%.2f",M);
}
