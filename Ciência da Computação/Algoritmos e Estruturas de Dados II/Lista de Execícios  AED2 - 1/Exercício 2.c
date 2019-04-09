#include<stdio.h>

int Fat(int N)
{
    return (N==0)? 1 : N*Fat(N-1);
}


double Seq(int N)
{
    return (N==1)? 1 : 1/(double)Fat(N) + (Seq(N-1));
}


int main()
{
   int N;
   while(scanf("%d",&N)!=EOF)
   {
       printf("%.4lf\n",Seq(N)+1);
   }
}
