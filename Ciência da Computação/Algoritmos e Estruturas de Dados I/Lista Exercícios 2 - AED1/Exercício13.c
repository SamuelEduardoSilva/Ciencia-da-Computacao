// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
   int C,Q;
   float V;
   setlocale(LC_ALL,"Portuguese");
   printf("Card�pio da Lanchonete!\n\n");
   printf("Cachorro Quente - Pre�o:R$1,10 - C�digo:100\n");
   printf("Bauru Simples - Pre�o:R$1,30 - C�digo:101\n");
   printf("Bauru com ovo - Pre�o:R$1,50 - C�digo:102\n");
   printf("Cheeseburger - Pre�o:R$1,30 - C�digo:103\n");
   printf("\nDigite o c�digo da op��o desejada:\n");
   scanf("%i",&C);
   printf("Digite a quantidade desejada:\n");
   scanf("%i",&Q);
   switch (C){
     case 100:
        V=Q*1.1;
        printf("A op��o desejada foi Cachorro Quente!\n");
        printf("O valor a ser pago pela quantidade:%i,�:R$%.2f",Q,V);
        break;
     case 101:
        V=Q*1.3;
        printf("A op��o desejada foi Bauru Simples!\n");
        printf("O valor a ser pego pela quantidade:%i,�:R$%.2f",Q,V);
        break;
     case 102:
        V=Q*1.5;
        printf("A op��o desejada foi Bauru com ovo!\n");
        printf("O valor a ser pago pela quantidade:%i,�:R$%.2f",Q,V);
        break;
     case 103:
        V=Q*1.3;
        printf("A op��o desejada foi Cheeseburger!\n");
        printf("O valor a ser pago pela quantidade:%i,�:R$%.2f",Q,V);
        break;
     default:
        printf("Op��o inv�lida!");
  getch();
  return 0;
}
}
