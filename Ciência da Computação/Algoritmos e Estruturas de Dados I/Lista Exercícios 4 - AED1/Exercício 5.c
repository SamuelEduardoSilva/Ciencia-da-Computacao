//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguse");
  int N,cont=0;
  while (scanf("%i",&N),N!=0){
    if (N>=100 && N<=200)
        cont++;
  }
  printf("O número de números digitados entre 100 e 200,foi:%i",cont);
  return 0;
}
