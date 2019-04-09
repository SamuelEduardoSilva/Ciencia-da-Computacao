//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
   float NH,VH,SB,SL,INSS,SIN,IR;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite o número de horas trabalhadas:\n");
   scanf("%f",&NH);
   printf("Digite o valor da hora trabalhada:\n");
   scanf("%f",&VH);
   SB=NH*VH;
   INSS=SB*0.08;
   SIN=SB*0.05;
   IR=SB*0.11;
   SL=SB-INSS-SIN-IR;
   printf("O salário bruto é:R$%.2f\n",SB);
   printf("Foram pagos ao INSS:R$%.2f\n",INSS);
   printf("Foram pagos ao sindicato:R$%.2f\n",SIN);
   printf("O salário líquido é:R$%.2f\n",SL);
   // Não foi pedido que mostrasse o valor pago de Imposto de Renda no exercicio,portanto,não coloquei.
   return 0;


}
