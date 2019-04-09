#include<stdio.h>
#include<string.h>
#include<locale.h>


int main(){
   setlocale(LC_ALL,"Portuguese");
   char S[100];
   int i=0;
   int c=0;
   printf("Digite a string:\n");
   scanf("%100[^\n]",S);
   getchar();
   while (S[i]!='\0'){
    c++;
    i++;
   }
   printf("A string digitada tem %d caracteres!\n",c);
}
