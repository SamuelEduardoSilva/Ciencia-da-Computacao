// Feito por Samuel Eduardo da Silva
#include<stdio.h>

int main(){
  int i,X=1,mult;
  printf("Tabuada dos numeros de 1 a 10:\n\n");
  do{
    for (i=0;i<=10;i++){
        mult=X*i;
        printf("%i X %i = %i\n",X,i,mult);
    }
    X++;
    printf("\n");
  }while(X<11);
}
