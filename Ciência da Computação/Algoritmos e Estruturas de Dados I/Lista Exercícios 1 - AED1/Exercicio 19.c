//Feito por Samuel Eduardo da Silva
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
int main(){
   float T,LP,GP,LG,LGP;
   int L,G;
   setlocale(LC_ALL, "Portuguese");
   printf("Digite a �rea a ser pintada,em metros quadrados:\n");
   scanf("%f",&T);
   L=ceil(T/18/6);
   LP=L*80;
   G=ceil(T/3.6/6);
   GP=G*25;
   printf("A quantidade de latas necess�rias �:%.2d\n",L);
   printf("O valor a ser pago comprando em latas de tinta �:R$%.2f\n\n",LP);
   printf("A quantidade de galoes necess�rios �:%.2d\n",G);
   printf("O valor a ser pago comprando em gal�es de tinta �:R$%.2f\n\n",GP);
   L=floor(T/108);
   G=ceil((T-(L*18*6))/3.6/6);
     if (G > 3) {
      G = 0;
      L = L + 1;
   }
   LP=L*80;
   GP=G*25;
   printf("Misturando latas e gal�es,ser� necessario a quantidade de:%d latas e %d gal�es\n",L,G);
   printf("O valor a ser pago �:R$%.2f\n", LP + GP);
   getch();
   return 0;
}
