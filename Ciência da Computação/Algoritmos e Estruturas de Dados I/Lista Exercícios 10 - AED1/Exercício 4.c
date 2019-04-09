#include<stdio.h>
#include<locale.h>
double soma=0;
void Soma(int N)
{

    double i;

    for(i=1;i<=N;i++)
    {
        soma+=(((i*i)+1)/(i+3));
    }
}


int main()
{
    setlocale(LC_ALL,"Portuguese");
    int N;

    printf("Digite o valor de N:\n");
    scanf("%d",&N);
    Soma(N);
    printf("O valor da soma é: %.2lf\n",soma);

}

