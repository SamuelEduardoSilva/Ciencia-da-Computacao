#include<stdio.h>
#include<locale.h>
int main(){
  setlocale(LC_ALL,"Portuguese");
  int N[20];
  int i;
  int MV=10000;
  int V;
  int S=0;
  int contV=0;
  double M;
  for (i=0;i<20;i++){
    printf("Digite o tempo da %iº volta:\n",i+1);
    scanf("%i",&N[i]);
    if (N[i]<MV){
        MV=N[i];
        V=i+1;
    }
    S+=N[i];
  }
  M=S/20.0;
  printf("\n\tO melhor tempo foi: %i\n",MV);
  printf("\tA volta em que o melhor tempo ocorreu foi:%i\n",V);
  printf("\tO tempo médio das 20 voltas foi: %.1lf\n",M);
  for (i=0;i<20;i++){
    if (N[i]>M){
        contV++;
    }
  }
  printf("\tForam %i volta(s) que ficaram acima da média\n",contV);
}
