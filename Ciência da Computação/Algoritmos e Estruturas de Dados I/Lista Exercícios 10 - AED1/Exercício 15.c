#include<stdio.h>
#include<locale.h>
#include<stdbool.h>
double Me[10];
void Media(double Notas[10][4])
{
    int i,j;

    double soma=0;
    for(i=0;i<10;i++)
    {
        soma=0;
        for(j=0;j<4;j++)
        {
          soma+=Notas[i][j];
        }
        Me[i]=soma/4.0;
    }
}

bool Rec(double Me)
{


    if(Me<6.0)
        return true;
    else
        return false;

}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    char Aluno[10][50];
    double Notas[10][4];
    int i,j,k;

    printf("Digite o nome dos alunos  e suas respectivas notas:\n");

    for(i=0;i<10;i++)
    {
        printf("Aluno %d:\n",i+1);
        scanf("%50[^\n]",Aluno[i]);
        getchar();
        for(j=0;j<4;j++)
        {
            printf("%dº prova:\n",j+1);
            scanf("%lf",&Notas[i][j]);
            getchar();
        }
    }
    printf("\nAlunos e suas respectivas médias aritméticas:\n");
    Media(Notas);
    for(i=0;i<10;i++)
    {
        printf("%s = %.1lf\n",Aluno[i],Me[i]);
    }
    printf("\nAlunos em recuperação:\n");
    for(i=0;i<10;i++)
    {
        if(Rec(Me[i]))
            printf("%s\n",Aluno[i]);
    }
}
