#include<stdio.h>
#include<string.h>
#include<locale.h>


int main(){
   setlocale(LC_ALL,"Portuguese");
   char N[12][50];
   int I[12];
   char S[12];
   int i;

   for(i=0;i<12;i++)
   {
       printf("Digite o nome da %dº pessoa:\n",i+1);
       scanf("%50[^\n]",N[i]);
       getchar();
       printf("Digite a idade da %dº pessoa:\n",i+1);
       scanf("%d",&I[i]);
       getchar();
       printf("Digite o sexo da %dº pessoa:\n",i+1);
       scanf("%c",&S[i]);
       getchar();
       printf("\n");
   }
   printf("\n\nInformações das pessoas do sexo masculino e maiores de 18:\n");
   printf("\tNome\t\t\t\tIdade\tSexo\n");
   for (i=0;i<12;i++)
   {
       if (I[i]>18 && S[i]=='m')
        printf("\t%s\t\t\t\t%d\t%c\n",N[i],I[i],S[i]);
   }
}
