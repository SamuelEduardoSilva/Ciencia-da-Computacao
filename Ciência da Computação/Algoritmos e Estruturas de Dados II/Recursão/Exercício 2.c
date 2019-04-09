#include<stdio.h>

int Pot(int X,int Y)
{
    if(Y==0)
        return 1;
   return X*Pot(X,Y-1);
}

int main()
{
    int X,Y;
    while(scanf("%d %d",&X,&Y)!=EOF)
    {
        printf("Pot(%d,%d) = %d\n",X,Y,Pot(X,Y));
    }
}
