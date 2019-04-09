#include<stdio.h>
#include<string.h>

int main(){

   char P[100];
   int i,j,k;

   printf("Digite a string:\n");
   scanf("%100[^\n]",P);
   printf("Digite o valor de i e j,respectivamente:\n");
   scanf("%d %d",&i,&j);

   for(k=i;k<=j;k++)
   {
       printf("%c",P[k]);
   }

}
