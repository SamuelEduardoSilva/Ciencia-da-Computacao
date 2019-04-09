// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
   setlocale(LC_ALL,"Portuguese");
  int N,i=2,cont=0;
  scanf("%i",&N);
  do{
    if  (N%i==0)
        cont++;
        i++;
  }while(i<=N);
  if (cont==1)
    printf("O numero digitado é primo!\n");
  else
    printf("O numero digitado não é primo\n");
}
