#include<stdio.h>
void Zerin(int V[])
{
    int i;
    for(i=0;i<25;i++)
    {
        V[i]=0;
    }
}

int main()
{
    int V[25];
    int i;
    printf("Preencha aqui o vetor:\n");
    for(i=0;i<25;i++)
    {
        scanf("%d",&V[i]);
    }
    Zerin(V);
    printf("O novo vetor:\n");
    for(i=0;i<25;i++)
    {
        printf("[%d] = [%d]\n",i,V[i]);
    }
}
