//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
   float SF,SM,QS;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite o salário do funcionario:\n");
   scanf("%f",&SF);
   printf("Digite o valor do salário mínimo:\n");
   scanf("%f",&SM);
   QS=SF/SM;
   printf("Esse funcionario recebe %.2f salarios minimos",QS);
   return 0;

}
