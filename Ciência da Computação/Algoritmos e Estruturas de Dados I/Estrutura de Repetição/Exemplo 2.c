#include<stdio.h>

main(){
  int X,Y,Cont;
  printf("Digite um valor para X:\n");
  scanf("%i",&X);
  Y=X;

  for (Cont=0;Cont<4;Cont++){
    Y=X*Y;
}
printf("O valor de Y eh:%i",Y);
}

