#include<stdio.h>
#include<locale.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
  int Vet[20];
  int cont=0;
  int i;
  for (i=0;i<20;i++){
    printf("Digite o %i° número do vetor:\n",i+1);
    scanf("%i",&Vet[i]);
    if (Vet[i]%2==0)
        cont++;
  }
  for (i=0;i<20;i++){
    printf("Vet[%i] = %i\n",i,Vet[i]);
  }
  printf("Existem %i valores pares nesse vetor!\n",cont);
}
