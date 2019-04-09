#include<stdio.h>

int main()
{
    int M[5][5];
    int VL[5];
    int VC[5];
    int i,j;
    memset(&VC,0,sizeof(VC));
    memset(&VL,0,sizeof(VL));

    for(i=0;i<5;i++){

        for(j=0;j<5;j++){
            printf("Digite o [%d][%d] valor da matriz:\n",i,j);
            scanf("%d",&M[i][j]);
            VL[i]+=M[i][j];
            VC[j]+=M[i][j];
      }
    }
    printf("Matriz digitada:\n\n");

    for(i=0;i<5;i++){
        for(j=0;j<5;j++)
        {
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }

    printf("Vetor da soma das linhas\n\n");
    for(i=0;i<5;i++)
    {
        printf("SL[%d] = %d\n",i,VL[i]);
    }
    printf("Vetor da soma das colunas\n\n");
    for(i=0;i<5;i++)
    {
        printf("SL[%d] = %d\n",i,VC[i]);
    }
}
