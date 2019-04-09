#include<stdio.h>

int DS(int M[6][6])
{
    int i,j;
    int Me;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if  (j==6-1-i )
            {
                if(j==5)
                    Me=M[i][j];
                else
                {
                    if(M[i][j]<Me)
                        Me=M[i][j];
                }
            }
        }
    }
    return Me;
}


int main()
{
    int M[6][6];
    int i,j;
    printf("Preencha a matriz:\n");
    for(i=0;i<6;i++){
        for(j=0;j<6;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    printf("O menor elemento da diagonal secundario eh: %d\n",DS(M));
}
