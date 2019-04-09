// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<conio.h>
#include <locale.h>

int main(){
   int A,B,C,MAIOR,INTER,MENOR;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite o primeiro valor:\n");
   scanf("%i",&A);
   printf("Digite o segundo valor:\n");
   scanf("%i",&B);
   printf("Digite o terceiro valor:\n");
   scanf("%i",&C);
   if (( A < B ) && ( A < C )){
       MENOR = A;
       if (B>C){
         MAIOR=B;
         INTER=C;
       }
       else {
         MAIOR=C;
         INTER=B;
       }

       printf("O maior valor é: %i ,o intermediario é: %i e o menor é: %.i !",MAIOR,INTER,MENOR);
   }
   else if (( B < A ) && ( B < C )){
       MENOR = B;
       if (A>B){
         MAIOR=A;
         INTER=B;
       }
       else {
         MAIOR=B;
         INTER=A;
       }

       printf("O maior valor é: %i ,o intermediario é: %i e o menor é: %.i !",MAIOR,INTER,MENOR);
   }
   else if (( C < A ) && ( C < B )){
       MENOR = C;
       if (A>B){
         MAIOR=A;
         INTER=B;
       }
       else {
         MAIOR=B;
         INTER=A;
       }

       printf("O maior valor é: %i ,o intermediario é: %i e o menor é: %i !",MAIOR,INTER,MENOR);
   }
 getch();
 return 0;
}
