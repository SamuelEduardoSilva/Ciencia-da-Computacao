// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
    int i,QuantidadeIngresso=120,MaiorQI;
    double ValorIngresso=5.00,Despesa,Lucro,MaiorLucro=0;
    double MaiorPI;
    printf("Para o valor ingresso de:R$5.00,o lucro foi de:R$400,00\n");
    do{
       ValorIngresso-=0.50;
       QuantidadeIngresso+=26;
       Despesa=200;
       Lucro=(QuantidadeIngresso*ValorIngresso)-Despesa;
       if (Lucro>MaiorLucro){
        MaiorLucro=Lucro;
        MaiorPI=ValorIngresso;
        MaiorQI=QuantidadeIngresso;
       }
       printf("Para o valor ingresso de:R$%.2lf,o lucro foi de:R$%.2lf\n",ValorIngresso,Lucro);
       i++;

    }while(i<10);
    printf("O maior lucro foi de:%.2lf.\nO valor do ingresso para sua obtencao foi de:%.2lf\nE a quantidade de ingressos vendidos:%i\n",MaiorLucro,MaiorPI,MaiorQI);
    return 0;
}
