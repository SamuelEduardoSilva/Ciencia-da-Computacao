#include<stdio.h>
#include<locale.h>
struct R
{
    char N[50];
    long int T;
    double P;
};


int main()
{
    setlocale(LC_ALL,"Portuguese");
    struct R X[15];
    int i;
    double soma=0;
    double media;

    for(i=0;i<15;i++)
    {
        printf("Digite o nome da %dº loja:\n",i+1);
        scanf("%50[^\n]",X[i].N);
        getchar();
        printf("Digite o %dº telefone:\n",i+1);
        scanf("%li",&X[i].T);
        getchar();
        printf("Digite o %dº preço:\n",i+1);
        scanf("%lf",&X[i].P);
        getchar();
        soma+=X[i].P;
        printf("\n\n");

    }
    media=soma/15.0;
    printf("A média dos preços foi: R$%.2lf!\n\n",media);
    printf("Lojas e seus respectivos telefones,em que o preço ficou abaixo da média:\n\n");
    printf("Nome\t\tTelefone\n\n");
    for(i=0;i<15;i++)
    {
        if(X[i].P<media)
            printf("%s\t%li\n",X[i].N,X[i].T);
    }
}
