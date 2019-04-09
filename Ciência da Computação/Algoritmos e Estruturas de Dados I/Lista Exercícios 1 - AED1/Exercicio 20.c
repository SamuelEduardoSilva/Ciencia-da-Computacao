//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
#include<conio.h>
int main(){
   float TA,VL,TE,VD,n;
   setlocale(LC_ALL,"Portuguese");
   while (n--){
   printf("Digite o tamanho do arquivo que deseja-se baixar em MB:\n");
   scanf("%f",&TA);
   printf("Digite a velocidade do link de internet em Mbps:\n");
   scanf("%f",&VL);
   VD=((VL*1000000)/8)/1024;
   //VD para representar Velocidade de Download dado em Kbts por segundo
   TE=((TA*1000)/VD)/60;
   printf("O tempo de download e aproximadamente:%.2f minutos\n\n",TE);
   }
   return 0;
   getch();

}
