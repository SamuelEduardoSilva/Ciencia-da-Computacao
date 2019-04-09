#include<stdio.h>


int Soma(int *v, int n)
{
     if(n==0)
        return 0;
      int soma=Soma(v, n-1);
      soma += v[n-1];
      return  soma;

}


int main()
{
   int i;
   int Vet[6];

   printf("Preencha o vetor:\n");
   for(i=0;i<6;i++)
   {
       scanf("%d",&Vet[i]);
   }
   printf("A soma dos elementos desse vetor eh: %d\n",Soma(Vet,6));


}

