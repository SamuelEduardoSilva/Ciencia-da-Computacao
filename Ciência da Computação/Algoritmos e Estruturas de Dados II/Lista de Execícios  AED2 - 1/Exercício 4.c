#include<stdio.h>

int Maior (int *v, int n)
{
    if(n==0)
        return v[0];
    int maior = Maior(v,n-1);
      if(v[n-1]>maior)
        maior=v[n-1];


      return maior;

}


int main()
{
   int i;
   int T;
   int Vet[1002];

   printf("Digite o tamanho do vetor:\n");
   scanf("%d",&T);
   printf("Preencha o vetor:\n");
   for(i=0;i<T;i++)
   {
       scanf("%d",&Vet[i]);
   }
   printf("O maior dos elementos desse vetor eh: %d\n",Maior(Vet,T));


}


