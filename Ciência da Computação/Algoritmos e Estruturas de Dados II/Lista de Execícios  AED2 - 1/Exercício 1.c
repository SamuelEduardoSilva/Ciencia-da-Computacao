#include<stdio.h>

double Seq(int N)
{
    return (N==0) ? 0 : 1/(double)N + (Seq(N-1));
}


int main()
{
   int N;
   printf("Digite o valor de N:\n");
   while(scanf("%d",&N)!=EOF)
   {
       printf("Seq[%d] = %.2lf\n",N,Seq(N));
   }


}
