//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
int main(){
   float Q,QD,QM,QL;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite sua quantia em reais:\n");
   scanf("%f",&Q);
   QD=(Q/1.8);
   QM=(Q/2);
   QL=(Q/1.57);
   printf("A conversão para dolares é %.2f\n",QD);
   printf("A conversão para marcos alemães é %.2f\n",QM);
   printf("A conversão para libras esterlinas é %.2f\n",QL);
   return 0;
}
