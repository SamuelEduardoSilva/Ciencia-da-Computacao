#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdbool.h>
struct Humanas
{
    int Cod;
    char D;
    char NO[50];
    char NA[50];
    char Edi[50];
};
struct Exatas
{
    int Cod;
    char D;
    char NO[50];
    char NA[50];
    char Edi[50];
};
struct Bio
{
    int Cod;
    char D;
    char NO[50];
    char NA[50];
    char Edi[50];
};
int main()
{
    setlocale(LC_ALL,"Portuguese");

    struct Humanas X[500];
    struct Exatas Y[500];
    struct Bio Z[500];
    int i;
    int op;
    char Ar;
    int PC;
    printf("Cadastre aqui as obras de Humanas:\n");
    bool M=false;
    for(i=0;i<500;i++)
    {
        printf("%d� Obra:\n",i+1);
        printf("C�digo: ");
        scanf("%d",&X[i].Cod);
        getchar();
        printf("Doa��o ? : ");
        scanf("%c",&X[i].D);
        getchar();
        printf("Nome: ");
        scanf("%50[^\n]",&X[i].NO);
        getchar();
        printf("Autor: ");
        scanf("%50[^\n]",&X[i].NA);
        getchar();
        printf("Editora: ");
        scanf("%50[^\n]",&X[i].Edi);
        getchar();
    }
    printf("\n\nCadastre aqui as obras de Exatas:\n");
    for(i=0;i<500;i++)
    {
        printf("%d� Obra:\n",i+1);
        printf("C�digo: ");
        scanf("%d",&Y[i].Cod);
        getchar();
        printf("Doa��o ? : ");
        scanf("%c",&Y[i].D);
        getchar();
        printf("Nome: ");
        scanf("%50[^\n]",&Y[i].NO);
        getchar();
        printf("Autor: ");
        scanf("%50[^\n]",&Y[i].NA);
        getchar();
        printf("Editora: ");
        scanf("%50[^\n]",&Y[i].Edi);
        getchar();
    }
    printf("\n\nCadastre aqui as obras de Biol�gicas:\n");
    for(i=0;i<500;i++)
    {
        printf("%d� Obra:\n",i+1);
        printf("C�digo: ");
        scanf("%d",&Z[i].Cod);
        getchar();
        printf("Doa��o ? : ");
        scanf("%c",&Z[i].D);
        getchar();
        printf("Nome: ");
        scanf("%50[^\n]",Z[i].NO);
        getchar();
        printf("Autor: ");
        scanf("%50[^\n]",Z[i].NA);
        getchar();
        printf("Editora: ");
        scanf("%50[^\n]",Z[i].Edi);
        getchar();
    }
    printf("\n\n\tPara pesquisar digite 1,para sair,digite -1\n");
    scanf("%d",&op);
    getchar();
    do{
       if(op==1){
       printf("Digite a �rea do livro que se deseja pesquisar:\n");
       printf("H - Humanas || E - Exatas || B - Biol�gicas\n\n");
       scanf("%c",Ar);
       getchar();
       if(Ar=='H'){
          printf("Area desejada : Humanas!\n");
          printf("Digite agora o c�digo da obra desejada:\n");
          scanf("%d",&PC);
          for(i=0;i<500;i++)

          {
              if(PC==X[i].Cod){
                printf("Dados da obra digitada:\n");
                printf("Nome: %s\n",X[i].NO);
                printf("Autor: %s\n",X[i].NA);
                printf("Editora: %s\n",X[i].Edi);
                printf("Para doa��o ? : %c\n",X[i].D);
                M=true;
              }

          }
          if(!M)
            printf("C�digo inv�lido!\n");


       }
       else if(Ar=='E'){
          printf("Area desejada : Exatas!\n");
          printf("Digite agora o c�digo da obra desejada:\n");
          scanf("%d",&PC);
          for(i=0;i<500;i++)
          {
              if(PC==Y[i].Cod){
                printf("Dados da obra digitada:\n");
                printf("Nome: %s\n",Y[i].NO);
                printf("Autor: %s\n",Y[i].NA);
                printf("Editora: %s\n",Y[i].Edi);
                printf("Para doa��o ? : %c\n",Y[i].D);
                M=true;
              }

          }
          if(!M)
            printf("C�digo inv�lido!\n");

       }
       else if(Ar=='B'){
          printf("Area desejada : Biol�gicas!\n");
          printf("Digite agora o c�digo da obra desejada:\n");
          scanf("%d",&PC);
          for(i=0;i<500;i++)
          {
              if(PC==Z[i].Cod){
                printf("Dados da obra digitada:\n");
                printf("Nome: %s\n",Z[i].NO);
                printf("Autor: %s\n",Z[i].NA);
                printf("Editora: %s\n",Z[i].Edi);
                printf("Para doa��o ? : %c\n",Z[i].D);
                M=true;
              }

          }
          if(!M)
            printf("C�digo inv�lido!\n");

       }

       else
         printf("Area inv�lida!\n");
       }
       else
        printf("Op��o inv�lida!\n");


     M=false;
     printf("\n\n\tPara pesquisar novamente digite 1,para sair,digite -1\n");
     scanf("%d",&op);
     getchar();
    }while(op!=-1);


}
