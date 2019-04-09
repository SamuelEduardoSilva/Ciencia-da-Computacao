//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
#include<math.h>

int main(){
   float QOti=0,QBom=0,QReg=0,QRui=0,QPess=0,Qtotal=0,Soma=0;
   int maiorPessima=0,maiorOtimo=0,maiorRuim=0,DOR=0;
   double PercentBom,PercentReg,DifePercentBomReg,MediaRuim,PercentPess;
   int i,idade,opi;
   setlocale(LC_ALL,"Portuguese");
   for (i=0;i<100;i++){
    printf("Digite sua idade:\n");
    scanf("%i",&idade);
    printf("Digite sua opiniao: 1-Ótimo | 2-Bom | 3-Regular | 4-Ruim | 5-Péssimo\n");
    scanf("%i",&opi);
    switch (opi){
       case 1:
           QOti++;
            if (idade>maiorOtimo){
            maiorOtimo=idade;
           }
       break;
       case 2:
           QBom++;

       break;
       case 3:
           QReg++;
       break;
       case 4:
           QRui++;
           Soma=Soma+idade;
           if (idade>maiorRuim){
            maiorRuim=idade;
           }
       break;
       case 5:
           QPess++;
           if (idade>maiorPessima){
            maiorPessima=idade;
           }
       break;
       default:
        printf("Opção de opiniao invalida!\n");
    }
   }
   Qtotal=100;
   PercentBom=((QBom/Qtotal)*100);
   PercentReg=((QReg/Qtotal)*100);
   DifePercentBomReg=fabs(PercentBom-PercentReg);
   MediaRuim=Soma/(float)QRui;
   PercentPess=((QPess/Qtotal)*100);
   DOR=fabs(maiorOtimo-maiorRuim);

   printf("Quantidade de respostas Otimo: %.0f\n",QOti);
   printf("Diferença da porcentagem Bom e Regular: %.2lf%%\n",DifePercentBomReg);
   printf("Média idade pessoas que responderam ruim: %.2f\n",MediaRuim);
   printf("Porcentagem respostas Péssimo foi: %.2lf%% e maior idade dessa opção: %i\n",PercentPess,maiorPessima);
   printf("Diferença maior idade que respondeu Ótimo e Ruim foi: %i\n",DOR);
  return 0;
}

