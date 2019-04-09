//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
#include<math.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  float soma=0,i=1;
  while (i<=10){
    printf("%.0f\n",i);
    soma+=pow(i,3);
    i++;
  }
  printf("A soma dos cubos desses números é:%.0f",soma);
  return 0;
}
