//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
   float CC,CF;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite o custo de f�brica:\n");
   scanf("%f",&CF);
   CC=CF+(CF*0.12)+(CF*0.30);
   printf("O custo do consumidor �:R$%.2f",CC);
   return 0;


}
