#include<stdio.h>
#include<locale.h>


int Soma(int N)
{
    int i;
    int soma=0;
    for(i=1;i<=N;i++)
    {
        soma+=i;
    }
    return soma;
}

int main()
{
    int N;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o N:\n");
    scanf("%d",&N);


    printf("A soma é: %d\n",Soma(N));

}
