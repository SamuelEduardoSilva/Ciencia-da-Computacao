#include<stdio.h>
#include<locale.h>
int fat(int v)
{
    if(v==0)
        return 1;
    return fat(v-1)*v;
}


double Soma(int N)
{
    double soma=1;
    int i;
    for(i=1;i<=N;i++)
    {
        soma+=(1.0/fat(i));
    }
    return soma;
}


int main()
{
    setlocale(LC_ALL,"Portuguese");
    int N;
    printf("Digite o valor de N:\n");
    scanf("%d",&N);
    printf("O valor da soma é: %.2lf\n",Soma(N));

    return 0;
}
