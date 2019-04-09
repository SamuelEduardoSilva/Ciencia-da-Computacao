#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int X[12],Y[12];
  int i;
  for (i=0;i<12;i++){
    printf("Digite o %i° número do vetor:\n",i+1);
    scanf("%i",&X[i]);
    Y[i]=X[i];
    if (X[i]==0)
        Y[i]=1;
  }
  printf("Primeiro vetor:\n");
  for (i=0;i<12;i++){
    printf("[%i] = %i\n",i,X[i]);
  }
  printf("Segundo vetor:\n");
  for (i=0;i<12;i++){

    printf("[%i] = %i\n",i,Y[i]);
  }
}
