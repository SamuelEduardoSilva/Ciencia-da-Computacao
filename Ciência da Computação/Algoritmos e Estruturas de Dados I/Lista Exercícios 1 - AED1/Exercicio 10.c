//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
int main(){
   int NN,NA,IA,IM;
   float ID,IS;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite o ano de nascimento:\n");
   scanf("%i",&NN);
   printf("Digite o ano atual:\n");
   scanf("%i",&NA);
   IA=NA-NN;
   IM=(NA-NN)*12;
   ID=(NA-NN)*365.25;
   IS=ID/7;
   printf("A idade em anos �:%i\n",IA);
   printf("A idade em meses �: %2.i\n",IM);
   printf("A idade em dias �: %.2f\n",ID);
   printf("A idade em semanas �: %.2f\n",IS);
   return 0;
}
