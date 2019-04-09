//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
   float a11,a12,a21,a22,M;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite o valor para a11:\n");
   scanf("%f",&a11);
   printf("Digite o valor para a12:\n");
   scanf("%f",&a12);
   printf("Digite o valor para a21:\n");
   scanf("%f",&a21);
   printf("Digite o valor para a22:\n");
   scanf("%f",&a22);
   M=(a11*a22)-(a21*a12);
   printf("O determinante dessa matriz é:%.2f",M);
   return 0;

}
