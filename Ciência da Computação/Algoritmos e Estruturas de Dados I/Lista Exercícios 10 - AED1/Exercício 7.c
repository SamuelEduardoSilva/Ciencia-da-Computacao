#include<stdio.h>
#include<locale.h>
int N[10];
int fat(int v)
{
    if(v==0)
        return 1;
    return fat(v-1)*v;
}

void VetFat(int X[])
{
    int i;
    for(i=0;i<10;i++)
    {
        X[i]=fat(X[i]);
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int N[10];
    int i;
    printf("Preencha aqui um vetor de 10 posições:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&N[i]);
    }
    VetFat(N);
    printf("O vetor agora fatoriado:\n");
    for(i=0;i<10;i++)
    {
        printf("[%d]\n",N[i]);
    }
}
