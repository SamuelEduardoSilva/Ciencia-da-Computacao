//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include <math.h>
#include<locale.h>

int main(){
   float T,P;
   int QL;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite a área a ser pintada em metros quadrados:\n");
   scanf("%f",&T);
   QL=ceil(T/54);
   P=QL*80;
   printf("A quantidade de latas de tintas necessarias é:%d\n",QL);
   printf("O valor a ser pago é:R$%.2f\n",P);
   return 0;
}
