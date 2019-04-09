#include<stdio.h>
#include<locale.h>

int main(){
   setlocale(LC_ALL,"Portuguese");
   int n;
   int i;
   int soma=0;
   printf("Digite o valor para N:\n");
   scanf("%d",&n);
   int X[n],Y[n];
   for (i=0;i<n;i++){
    printf("Digite o %iº do vetor X:\n",i+1);
    scanf("%d",&X[i]);
   }
   for (i=0;i<n;i++){
    printf("Digite o %iº do vetor Y:\n",i+1);
    scanf("%d",&Y[i]);
   }
   for (i=0;i<n;i++){
    soma+=X[i]*Y[i];
   }
   printf("O produto escalar desses vetores é: %i\n",soma);
}
