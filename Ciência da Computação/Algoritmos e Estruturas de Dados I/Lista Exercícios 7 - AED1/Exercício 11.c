#include<stdio.h>
#include<string.h>
#include<locale.h>


int main(){
   setlocale(LC_ALL,"Portuguese");
   char S[100];
   char C;
   int i;
   int j=0;
   printf("Digite a string:\n");
   scanf("%100[^\n]",S);
   getchar();
   printf("Digite o caracter:\n");
   scanf("%c",&C);
   getchar();

   for(i=0;i<strlen(S);i++)
   {
       if (S[i]==C)
        j++;
   }
   printf("O caracter digitado,aparece %d veze(s) na string\n",j);

}

