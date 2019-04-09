//Feito por Samuel Eduardo da Silva
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
int main(){
   float T,LP,GP,LG,LGP;
   int L,G;
   setlocale(LC_ALL, "Portuguese");
   printf("Digite a área a ser pintada,em metros quadrados:\n");
   scanf("%f",&T);
   L=ceil(T/18/6);
   LP=L*80;
   G=ceil(T/3.6/6);
   GP=G*25;
   printf("A quantidade de latas necessárias é:%.2d\n",L);
   printf("O valor a ser pago comprando em latas de tinta é:R$%.2f\n\n",LP);
   printf("A quantidade de galoes necessários é:%.2d\n",G);
   printf("O valor a ser pago comprando em galões de tinta é:R$%.2f\n\n",GP);
   L=floor(T/108);
   G=ceil((T-(L*18*6))/3.6/6);
     if (G > 3) {
      G = 0;
      L = L + 1;
   }
   LP=L*80;
   GP=G*25;
   printf("Misturando latas e galões,será necessario a quantidade de:%d latas e %d galões\n",L,G);
   printf("O valor a ser pago é:R$%.2f\n", LP + GP);
   getch();
   return 0;
}
