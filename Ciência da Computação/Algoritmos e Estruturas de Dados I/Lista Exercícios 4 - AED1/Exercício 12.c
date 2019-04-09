//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  float PrecoCompra,PrecoVenda,Lucro,LucroTotal=0;
  char Acao;
  int cont1000=0,cont200=0;
  while (printf("Digite o tipo de ação:"),scanf("%c",&Acao),fflush(stdin),Acao!='F'){
      printf("Digite o preço de compra:R$");
      scanf("%f",&PrecoCompra);
      printf("Digite o preço de venda:R$");
      scanf("%f",&PrecoVenda);
      fflush(stdin);
      Lucro=PrecoVenda-PrecoCompra;
      LucroTotal+=Lucro;
      if (Lucro>1000)
        cont1000++;
      else if (Lucro<200)
        cont200++;
      printf("O lucro da ação %c foi de:R$%.2f\n\n",Acao,Lucro);
}
 printf("\nO lucro total da empresa foi de:R$%.2f",LucroTotal);
 printf("Quantidade de ações com lucro superio a R$1000.00 foi: %i\n",cont1000);
 printf("Quantidade de ações com lucro inferior a R$200.00 foi: %i\n",cont200);
 return 0;
}
