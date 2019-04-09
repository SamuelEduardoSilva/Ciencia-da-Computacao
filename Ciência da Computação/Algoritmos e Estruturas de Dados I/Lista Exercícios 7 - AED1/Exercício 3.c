#include<stdio.h>
#include<string.h>
#include<locale.h>
int main(){
   setlocale(LC_ALL,"Portuguese");
   char Frase[100];
   int i,j=0;

   printf("Digite a frase:\n");
   scanf("%100[^\n]",Frase);


   for(i=0;i<strlen(Frase);i++)
   {
       if (Frase[i]==' '){
           printf("%c",Frase[i+1]);
           j++;
           i++;
       }
       else
            printf("%c",Frase[i]);
   }
   printf("\n");
   printf("Houveram %d espaços\n",j);
}

