#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdbool.h>

int main(){
   setlocale(LC_ALL,"Portuguese");
   char SX[20]="admin";
   char LX[20]="admin";
   char S[20];
   char L[20];
   bool flag=false;

   printf("\t\tPara realizar o login,preencha os dados corretamente:\n\n\n\n");
   do{
   printf("\t\tLogin: ");
   scanf("%20[^\n]",L);
   getchar();
   printf("\t\tSenha: ");
   scanf("%20[^\n]",S);
   getchar();
   if (strcmp(SX,S)==0&&strcmp(LX,L)==0){
     printf("\n\t\tLogin realizado com sucesso!\n");
     flag=true;
   }
   else
     printf("\n\t\tLogin ou senha incorretos!\n\n");
   }while(flag==false);
}
