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
   printf("A convers�o para dolares � %.2f\n",QD);
   printf("A convers�o para marcos alem�es � %.2f\n",QM);
   printf("A convers�o para libras esterlinas � %.2f\n",QL);
   return 0;
}
