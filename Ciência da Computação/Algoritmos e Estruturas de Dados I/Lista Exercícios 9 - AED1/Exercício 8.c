#include<stdio.h>
#include<locale.h>

struct R
{
    long long int M;
    char N[50];
    double Med;
};


int main()
{
    setlocale(LC_ALL,"Portuguese");
    struct R X[10];
    int i;
    double Soma=0;
    double Media;
    int cont=0;
    double Perc;
    int k=0;
    for(i=0;i<10;i++)
    {
        printf("Digite a matrícula do %dº aluno:\n",i+1);
        scanf("%lli",&X[i].M);
        getchar();
        printf("Digite o nome do %dº aluno:\n",i+1);
        scanf("%50[^\n]",&X[i].N);
        getchar();
        if(X[i].N[0]=='L')
            k++;
        printf("Digite a média do %dº aluno:\n",i+1);
        scanf("%lf",&X[i].Med);
        fflush(stdin);
        Soma+=X[i].Med;
        printf("\n\n");
    }
    Media=Soma/10.0;
    Perc=((k/10.0)*100);
    for(i=0;i<3;i++)
    {
        if(X[i].Med>=7.0)
            cont++;
    }
    printf("A média da turma foi de: %.1lf\n",Media);
    printf("A porcentagem de alunos que tem a letra inicial L é: %.1lf\n",Perc);
    printf("A quantidade de alunos que tiveram média superior a 7 foi : %d\n",cont);

}
