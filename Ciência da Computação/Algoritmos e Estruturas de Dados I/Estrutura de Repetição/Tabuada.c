#include<stdio.h>

main(){
  int cont,valor,mult=0;
  printf("Digite um valor:\n",valor);
  scanf("%i",&valor);
  printf("A tabuada eh:\n");
  for (cont=0;cont<11;cont++){

    mult=cont*valor;

    printf("%i X %i = %i\n",valor,cont,mult);
  }
}

