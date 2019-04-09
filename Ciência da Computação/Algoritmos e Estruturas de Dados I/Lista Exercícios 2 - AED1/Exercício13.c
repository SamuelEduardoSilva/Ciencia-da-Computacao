// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
   int C,Q;
   float V;
   setlocale(LC_ALL,"Portuguese");
   printf("Cardápio da Lanchonete!\n\n");
   printf("Cachorro Quente - Preço:R$1,10 - Código:100\n");
   printf("Bauru Simples - Preço:R$1,30 - Código:101\n");
   printf("Bauru com ovo - Preço:R$1,50 - Código:102\n");
   printf("Cheeseburger - Preço:R$1,30 - Código:103\n");
   printf("\nDigite o código da opção desejada:\n");
   scanf("%i",&C);
   printf("Digite a quantidade desejada:\n");
   scanf("%i",&Q);
   switch (C){
     case 100:
        V=Q*1.1;
        printf("A opção desejada foi Cachorro Quente!\n");
        printf("O valor a ser pago pela quantidade:%i,é:R$%.2f",Q,V);
        break;
     case 101:
        V=Q*1.3;
        printf("A opção desejada foi Bauru Simples!\n");
        printf("O valor a ser pego pela quantidade:%i,é:R$%.2f",Q,V);
        break;
     case 102:
        V=Q*1.5;
        printf("A opção desejada foi Bauru com ovo!\n");
        printf("O valor a ser pago pela quantidade:%i,é:R$%.2f",Q,V);
        break;
     case 103:
        V=Q*1.3;
        printf("A opção desejada foi Cheeseburger!\n");
        printf("O valor a ser pago pela quantidade:%i,é:R$%.2f",Q,V);
        break;
     default:
        printf("Opção inválida!");
  getch();
  return 0;
}
}
