#include<stdio.h>
double X[12];

void Vet(double M[3][4])
{

    int k=0;
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            X[k]=M[i][j];
            k++;
        }
    }
}

int main()
{
    double M[3][4];
    int i,j;
    printf("Preencha aqui a matriz 3x4:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%lf",&M[i][j]);
        }
    }
    Vet(M);
    printf("A matriz agora em vetor:\n");
    for(i=0;i<12;i++)
    {
        printf("[%d] = [%.2lf]\n",i,X[i]);
    }
}
