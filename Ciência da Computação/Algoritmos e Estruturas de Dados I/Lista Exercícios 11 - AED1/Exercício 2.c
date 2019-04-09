#include<stdio.h>

int main()
{
    FILE *C;
    int Vet[10];
    int a=0;
    int i,j;
    int aux;
    C=fopen("Exercício 1.txt","r");
    if(C==NULL)
        printf("Erro na abertura!\n");
    else
    {
        while(!feof(C))
        {
          fscanf(C,"%d\n",&Vet[a]);
          a++;
        }

    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(Vet[i]>Vet[j])
            {
                aux=Vet[i];
                Vet[i]=Vet[j];
                Vet[j]=aux;
            }
        }
    }
    printf("O vetor do arquivo agora ordenado:\n");
    for(i=0;i<10;i++)
        printf("%d\n",Vet[i]);
    }
    fclose(C);
}
