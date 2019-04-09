//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
int main(){
   int H,HM,M,S,HMM;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite a hora:\n");
   scanf("%d",&H);
   printf("Digite os minutos:\n");
   scanf("%d",&M);
   HM=H*60;
   HMM=HM+M;
   S=HMM*60;
   printf("A hora digita convertida em minutos é:%d\n",HM);
   printf("O total de minutos é:%d\n",HMM);
   printf("O total de segundos é:%d\n",S);
   return 0;

}
