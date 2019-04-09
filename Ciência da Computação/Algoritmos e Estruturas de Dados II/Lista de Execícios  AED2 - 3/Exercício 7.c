#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int Matricula;
    char Nome[50];
    double N1;
    double N2;
    double R;
}matricula;


int main()
{

    matricula **x = (matricula**) malloc(25*sizeof(matricula*));
    int i;
    for(i=0;i<3;i++)
       x[i] = (matricula *)malloc(sizeof(matricula));

    printf("Preencha os dados dos 25 alunos:\n");

    for(i=0;i<25;i++)
    {
        printf("Aluno %d : \n",i+1);
        printf("Matricula = ");
        scanf("%d",&x[i]->Matricula);
        getchar();
        printf("Nome = ");
        scanf("%50[^\n]",&x[i]->Nome);
        getchar();
        printf("Nota 1 = ");
        scanf("%lf",&x[i]->N1);
        getchar();
        printf("Nota 2 = ");
        scanf("%lf",&x[i]->N2);
        getchar();
    }

    for(i=0;i<25;i++)
    {
        printf("Aluno %s = ",x[i]->Nome);
        if((x[i]->N1 + x[i]->N2) /2.0 >= 6.0)
            printf("Aprovado\n");
        else
            printf("Reprovado\n");
    }
    for(i=0;i<25;i++)
        free(x[i]);
    free(x);


    return 0;
}
