#include<stdio.h>

int Maior=-1;

void MA(int X[5][5])
{
    int i,j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(j>i)
            {
                if(X[i][j]>Maior)
                    Maior=X[i][j];
            }
        }
    }
}


int main()
{
    int M[5][5];
    int i,j;

    printf("Preencha aqui a matriz:\n");

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    MA(M);
    printf("\n\nO maior elemento acima da diagonal principal eh: %d\n",Maior);
}
