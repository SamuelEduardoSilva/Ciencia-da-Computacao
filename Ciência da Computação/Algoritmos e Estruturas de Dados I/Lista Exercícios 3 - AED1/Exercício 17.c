//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

main(){
  setlocale(LC_ALL,"Portuguese");
  int N,i,soma=0,X,j,cont=0;
  printf("Digite um n�mero,este ser� a quantidade de n�meros a seguir:\n");
  scanf("%i",&N);
  for (i=0;i<N;i++){
    printf("Digite um n�mero:\n");
    scanf("%i",&X);
    cont=0;
    for (j=2;j<=X;j++){
        if (X%j==0)
          cont++;

    }
    if (cont==1)
          soma+=X;
  }
  printf("A soma dos primos �: %i\n",soma);
}
