#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
   int vet[8];
   int i,j;
   int aux;
   for (i=0;i<8;i++){
    printf("Digite o %i� n�mero\n",i+1);
    scanf("%i",&vet[i]);
   }

   for (i=0;i<7;i++){
    for (j=i+1;j<8;j++){
     if (vet[i]>vet[j]){
      aux=vet[i];
      vet[i]=vet[j];
      vet[j]=aux;
   }
    }
   }
   printf("N�meros agora organizados em ordem crescente:\n");
   for (i=0;i<8;i++)
    printf("%i\n",vet[i]);
}
