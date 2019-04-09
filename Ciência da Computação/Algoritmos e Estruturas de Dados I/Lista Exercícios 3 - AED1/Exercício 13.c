//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL,"Portuguese");
   int Parcelas,i=0;
   double PF,ValorParcela,PC,Acres,Juros=0.03,PrecoAvista;
   printf("Digite o preço do carro:R$");
   scanf("%lf",&PC);
   PrecoAvista=PC*0.80;
   printf("Preço a vista: R$%.2lf\n",PrecoAvista);
   for (i=6;i<60;i+=6){
    Acres=PC*Juros;
    PF=PC+Acres;
    ValorParcela=PF/i;
    printf("Para quantidade de parcelas: %i\n",i);
    printf("O preço final é:R$%.2lf\n",PF);
    printf("O valor da parcela é:R$%.2lf\n\n",ValorParcela);
    Juros+=0.03;
   }
}
