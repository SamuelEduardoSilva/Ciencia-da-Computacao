// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  double ValorCompra,TotalVista=0,TotalPrazo=0,TotalCompras=0,ValorParcela;
  char TipoCompra;
  int i=0;
  do{
    printf("Digite o código:\n");
    scanf("%c",&TipoCompra);
    getchar();
    printf("Digite o valor da compra:\n");
    scanf("%lf",&ValorCompra);
    fflush(stdin);
    TotalCompras+=ValorCompra;
    if (TipoCompra=='V')
        TotalVista+=ValorCompra;
    else if (TipoCompra=='P'){
        TotalPrazo+=ValorCompra;
        ValorParcela=ValorCompra/3;
        printf("O valor da parcela é:R$%.2lf\n\n",ValorParcela);
  }
  i++;
  }while(i<15);
  printf("\nO valor total das compras a vista foi:R$%.2lf\n",TotalVista);
  printf("O valor total das compras a prazo foi:R$%.2lf\n",TotalPrazo);
  printf("O valor total das compras das compras foi:R$%.2lf\n",TotalCompras);
}
