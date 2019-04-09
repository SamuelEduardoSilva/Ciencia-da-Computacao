#include<stdio.h>
#include<locale.h>
int main(){
  setlocale(LC_ALL,"Portuguese");
  int N[8];
  int X[8];
  int Y[8];
  int i,j;
  int CP=0,CN=0;
  int CPT,CNT;
  for (i=0;i<8;i++){
    printf("Digite o %iº número do vetor:\n",i+1);
    scanf("%i",&N[i]);
    if (N[i]>0){
        X[CP]=N[i];
        CP++;

    }
    else if(N[i]<0){
        Y[CN]=N[i];
        CN++;
    }
  }
  printf("\n\n");
  CPT=CP;
  CNT=CN;
  printf("Vetor dos números positivos:\n");
  for (CP=0;CP<CPT;CP++){
    printf("Vet[%i] = %i\n",CP,X[CP]);
  }
  printf("Vetor dos números negativos:\n");
  for (CN=0;CN<CNT;CN++){
    printf("Vet[%i] = %i\n",CN,Y[CN]);
  }
  return 0;
}
