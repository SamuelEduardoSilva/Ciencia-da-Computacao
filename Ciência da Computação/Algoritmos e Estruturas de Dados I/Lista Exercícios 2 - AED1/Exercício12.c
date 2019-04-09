// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
   float SM,VC;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite o saldo médio:\n");
   scanf("%f",&SM);

   if ((SM>=0)&&(SM<=500))
      printf("Nenhum crédito\n");
   else if ((SM>500)&&(SM<=1000)){
      VC=SM*0.3;

      printf("O valor do crédito foi de:R$%.2f!",VC);
   }
   else if ((SM>1000)&&(SM<=3000)){
      VC=SM*0.4;

      printf("O valor do crédito foi de:R$%.2f!",VC);
   }
   else if (SM>3000){
      VC=SM*0.5;

      printf("O valor do crédito foi de:R$%.2f!",VC);
   }
   else
    printf("Valor negativo\n");
   getch();
   return 0 ;

}
