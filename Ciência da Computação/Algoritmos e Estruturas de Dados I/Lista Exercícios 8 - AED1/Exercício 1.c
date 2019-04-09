#include<stdio.h>

int main()
{
    int X,Y;
    int Z,V;
    printf("Digite as dimencoes das matrizes:\n");
    scanf("%d %d",&X,&Y);
    int M1[X][Y];
    int M2[X][Y];
    int MX[X][Y];
    int i,j;
    int Soma=0;
    printf("Preencha aqui as matrizes:\n");
    for(i=0;i<X;i++)
    {
        for(j=0;j<Y;j++)
        {
            scanf("%d",&M1[i][j]);
            scanf("%d",&M2[i][j]);
            MX[i][j]=M1[i][j]+M2[i][j];
        }
    }
    for(i=0;i<X;i++)
    {
        for(j=0;j<Y;j++)
        {
            printf("%d ",MX[i][j]);
        }
        printf("\n");
    }
}
