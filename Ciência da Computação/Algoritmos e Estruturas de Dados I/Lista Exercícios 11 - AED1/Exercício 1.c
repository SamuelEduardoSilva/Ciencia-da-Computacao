#include<stdio.h>

int main()
{
    int Vet[10];
    int i;
    printf("Preencha aqui o vetor:\n");
    for(i=0;i<10;i++)
        scanf("%d",&Vet[i]);
    FILE *C;

    C=fopen("Exercício 1.txt","a");
    if(C==NULL)
        printf("Erro na abertura!\n");
    else
    {
        for(i=0;i<10;i++)
           fprintf(C,"%d\n",Vet[i]);


    }
    fclose(C);

}
