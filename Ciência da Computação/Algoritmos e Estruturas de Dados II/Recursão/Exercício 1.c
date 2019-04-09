#include<stdio.h>

int Pot(int X,int Y)
{
    int result=1;
    int i;
    for(i=0;i<Y;i++)
        result*=X;

    return result;
}

int main()
{
    int X,Y;
    while(scanf("%d %d",&X,&Y)!=EOF)
    {
        printf("Pot(%d,%d) = %d\n",X,Y,Pot(X,Y));
    }
}
