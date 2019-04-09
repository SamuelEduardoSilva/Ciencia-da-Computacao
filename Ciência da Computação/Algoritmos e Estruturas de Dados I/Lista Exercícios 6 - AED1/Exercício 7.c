#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int A[20];
  int P=0;
  int B[P];
  int i;
  for (i=0;i<20;i++){
    printf("Digite o %iº do vetor:\n",i+1);
    scanf("%i",&A[i]);
    if (A[i]>0){
        B[P]=A[i];
        P++;
    }
  }
  printf("\n");
  for (i=0;i<P;i++){
    printf("Vetor B[%i] = %i\n",i,B[i]);
  }
}
