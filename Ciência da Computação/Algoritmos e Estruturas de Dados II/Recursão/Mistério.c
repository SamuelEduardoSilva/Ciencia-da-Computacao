#include<stdio.h>

int Misterio(int x,int y)
{
    int i;
    int result=0;

    for(i=0;i<y;i++)
       result+=x;

    return result;

}

int main()
{
    int x,y;

    while(scanf("%d %d",&x,&y)!=EOF)
    {
        printf("%d\n",Misterio(x,y));
    }
}
