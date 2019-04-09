#include<stdio.h>
#include<string.h>
#include<locale.h>


int main(){
   setlocale(LC_ALL,"Portuguese");
   char S[100];
   char SI[100];
   int i,k=0;
   printf("Digite a string:\n");
   scanf("%100[^\n]",S);
   getchar();
   for(i=strlen(S)-1;i>=0;i--)
   {
       SI[k]=S[i];
       k++;
   }
   for(i=0;i<strlen(S);i++)
   {
       printf("%c",SI[i]);
   }
}
