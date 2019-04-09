//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int N,i=1;
  scanf("%i",&N);
  printf("Os divisores desse número são:\n");
  while (i<=N){
        if (N%i==0){
         printf("%i\n",i);
         }
         i++;

  }
  return 0;
}
