#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>

int contaCidadaos;

struct cidadao
{
    char nome[50];
    char classe[50];
    char regiao[50];
    int idade;
    int QuantosOrcs;
    bool rei;
};

void Menu(FILE *a);

void Exclusao(FILE *registro)
{
    system("cls");
    rewind(registro);
    char cid[50];
    int i;
    printf("Digite o nome referente ao registro que será excluído: ");
    scanf("%[^\n]",cid);
    getchar();

    struct cidadao aux;
    struct cidadao todos[contaCidadaos];
    int flag = 0;
    int a = 0;
    for(i = 0 ; i < contaCidadaos; i++)
    {
        fread(&aux,sizeof(struct cidadao),1,registro);
        if(strcmp(aux.nome,cid) == 0)
        {
            flag = 1;
        }
        else
            todos[a++] = aux;
    }
    if(flag)
    {
        printf("Registro removido com sucesso!\n");
        contaCidadaos--;
        for(i = 0 ; i < contaCidadaos ; i++)
        {
            fclose(registro);
            FILE *novo = fopen("registro.dat","wb+");
            int i;
            for( i = 0 ; i < contaCidadaos; i++)
            {
                fwrite(&todos[i], sizeof(struct cidadao), 1, novo);
            }
            registro = novo;
        }
    }
    else
        printf("Registro não encontrado!\n");


    getch();
    Menu(registro);

}
int contaRelatorios = 1;

void Relatorio(FILE *registro)
{

    system("cls");

    char nomeRel[30] = {"relatorio"};

    int i;
    char n[4];
    memset(n,0,sizeof(n));
    sprintf(n,"%d",contaRelatorios);
    if(contaRelatorios>=0 && contaRelatorios <= 9)
    {
        strcat(nomeRel,"00");
        strcat(nomeRel,n);
    }
    else if(contaRelatorios>=10&& contaRelatorios <100)
    {
        strcat(nomeRel,"0");
        strcat(nomeRel,n);
    }
    else
        strcat(nomeRel,n);

    strcat(nomeRel,".txt");

    FILE *newRelatorio = fopen(nomeRel,"w");

    struct cidadao aux;

    rewind(registro);

    fputs("-- Relatório de Registros --\n\n",newRelatorio);

    for( i = 0 ; i < contaCidadaos ; i++)
    {
        fread(&aux,sizeof(struct cidadao),1,registro);

        fputs("Cidadão ",newRelatorio);

        char nC[30];
        memset(nC,0,sizeof(nC));
        sprintf(nC,"%d",i+1);

        fputs(nC,newRelatorio);
        fputs(":\n",newRelatorio);

        fputs("Nome: ",newRelatorio);
        fputs(aux.nome,newRelatorio);
        fputs(".\n",newRelatorio);

        fputs("Classe: ",newRelatorio);
        fputs(aux.classe,newRelatorio);
        fputs(".\n",newRelatorio);

        fputs("Região: ",newRelatorio);
        fputs(aux.regiao,newRelatorio);
        fputs(".\n",newRelatorio);

        memset(nC,0,sizeof(nC));
        sprintf(nC,"%d",aux.idade);
        fputs("Idade: ",newRelatorio);
        fputs(nC,newRelatorio);
        fputs(".\n",newRelatorio);

        memset(nC,0,sizeof(nC));
        sprintf(nC,"%d",aux.QuantosOrcs);
        fputs("Quantos Orcs assassinou: ",newRelatorio);
        fputs(nC,newRelatorio);
        fputs(".\n",newRelatorio);

        fputs("É rei: ",newRelatorio);
        if(aux.rei)
            fputs("Sim.\n",newRelatorio);
        else
            fputs("Não\n",newRelatorio);

        fputs("\n",newRelatorio);

    }
    fclose(newRelatorio);
    contaRelatorios++;
    printf("Novo relatório criado com sucesso!\n");
    getch();
    Menu(registro);

}

void Cadastro(FILE *registro)
{
    fclose(registro);

    registro = fopen("registro.dat","ab+");

    struct cidadao novoCidadao;
    system("cls");

    printf("-- Cadastro de um novo cidadão --\n\n");
    printf("Nome : ");
    scanf("%[^\n]",novoCidadao.nome);
    getchar();
    printf("Classe (Elfo | Anão | Humano | Orc | Maiar | Valar | Hobbit): ");
    scanf("%[^\n]",novoCidadao.classe);
    getchar();
    printf("Região: ");
    scanf("%[^\n]",novoCidadao.regiao);
    getchar();
    printf("Idade: ");
    scanf("%d",&novoCidadao.idade);
    getchar();
    printf("Quantos Orcs já matou: ");
    scanf("%d",&novoCidadao.QuantosOrcs);
    getchar();
    if(strcmp(novoCidadao.classe,"Orc") == 0 && novoCidadao.QuantosOrcs > 0)
    {
        FILE *orc = fopen("orc.txt","r");
        char ch = getc(orc);
        while(ch != EOF)
        {
            putchar(ch);
            ch = getc(orc);
        }
        fclose(orc);
        printf("TRAIDOR DE SANGUE!DIGA ONDE ELE ESTÁ QUE ESMAGAREI SEU CRÂNIO!!!\n");
    }

    printf("É rei ? (S - Sim | N - Não): ");
    char op;
    scanf("%c",&op);
    getchar();

    if(op == 'S')
        novoCidadao.rei = true;
    else
        novoCidadao.rei = false;

    fwrite(&novoCidadao, sizeof(struct cidadao), 1, registro);

    contaCidadaos++;

    printf("Cadastro feito com sucesso!\n");

    getch();

    Menu(registro);
}

void Consulta(FILE *registro)
{

    system("cls");
    int i;
    char search[50];

    printf("Digite o nome do cidadão:\n");
    scanf("%[^\n]",search);
    getchar();

    rewind(registro);

    int flag = 0;
    struct cidadao aux;
    for(i = 0 ; i < contaCidadaos ;i++)
    {
        fread(&aux,sizeof(struct cidadao),1,registro);
        if(strcmp(aux.nome,search) == 0)
        {
            printf("Dados do cidadão:\n");
            printf("Nome: %s\n",aux.nome);
            printf("Classe: %s\n",aux.classe);
            printf("Região: %s\n",aux.regiao);
            printf("Quantidade de Orcs assasinados: %s\n",aux.QuantosOrcs);
            printf("Já foi Rei ? : %s",(aux.rei)? "Sim\n" : "Não\n");
            flag = 1;
            break;
        }
    }
    if(!flag)
        printf("Registro não encontrado!\n");

    getch();
    Menu(registro);


}

void Alteracao(FILE *registro)
{
    int i;

    char cid[50];

    system("cls");


    printf("Digite o nome do cidadão: ");
    scanf("%[^\n]",cid);
    getchar();

    bool achou = 0;

    rewind(registro);


    struct cidadao todos[contaCidadaos];
    struct cidadao aux;
    for(i =0 ; i < contaCidadaos ; i++)
    {
        fread(&aux, sizeof(struct cidadao), 1, registro);
        todos[i] = aux;
        if(strcmp(aux.nome,cid) == 0)
        {
            achou = 1;
            printf("Encontramos seu registro, o que deseja alterar ?\n");
            printf("1 - Nome.\n");
            printf("2 - Classe.\n");
            printf("3 - Região.\n");
            printf("4 - Quantidade de Orcs assassinados.\n");
            printf("5 - Idade.\n");
            printf("6 - Se é rei.\n");
            char novo[50];

            switch(getch())
            {
               case '1':
               printf("Digite o novo nome: ");
               scanf("%[^\n]",novo);
               getchar();
               memset(todos[i].nome,0,sizeof(todos[i].nome));
               strcat(todos[i].nome,novo);
               break;

               case '2':
               printf("Digite a nova classe: ");
               scanf("%[^\n]",novo);
               getchar();
               memset(todos[i].classe,0,sizeof(todos[i].classe));
               strcat(todos[i].classe,novo);
               break;

               case '3':
               printf("Digite a nova região: ");
               scanf("%[^\n]",novo);
               getchar();
               memset(todos[i].regiao,0,sizeof(todos[i].regiao));
               strcat(todos[i].regiao,novo);

               break;

               case '4':
               printf("Digite a nova quantidade de Orc assassinados: ");
               scanf("%d",&todos[i].QuantosOrcs);
               getchar();
               break;

               case '5':
               printf("Digite a nova idade: ");
               scanf("%d",&todos[i].idade);
               getchar();
               break;

               case '6':
               printf("Digite 'S' se for Rei & 'N' se não for Rei: ");
               char op;
               scanf("%c",&op);
               getchar();
               if(op == 'S')
                todos[i].rei = true;
               else
                todos[i].rei = false;
               break;
               default:
                printf("Opção incorreta!\n");
                break;
            }

        }
    }
    if(!achou)
        printf("Não foram encontrados registros para esse nome!\n");
    else
    {
        fclose(registro);
        FILE *novo = fopen("registro.dat","wb+");
        int i;
        for( i = 0 ; i < contaCidadaos; i++)
        {
            fwrite(&todos[i], sizeof(struct cidadao), 1, novo);
        }
        printf("Registro alterado com sucesso!\n");
        registro = novo;
    }
    getch();

    Menu(registro);
}
void bye()
{
        system("cls");

        FILE *bye = fopen("temais.txt","r");
        char ch = getc(bye);
        while(ch != EOF)
        {
            putchar(ch);
            ch = getc(bye);
        }
        fclose(bye);
        printf("\nVOLTE SEMPRE!\n");
        exit(1);
}
void Menu(FILE *registro)
{
    system("cls");

    printf("REGISTRO DE CIDADÃOS - TERRA-MÉDIA E VALINOR\n");
    printf("1 - Cadastro.\n");
    printf("2 - Alteração.\n");
    printf("3 - Exclusão.\n");
    printf("4 - Consulta.\n");
    printf("5 - Criar novo relatório.\n");
    printf("6 - Sair.\n");


    switch(getch())
    {

       case '1' : Cadastro(registro);   break;
       case '2' : Alteracao(registro);   break;
       case '3' : Exclusao(registro);   break;
       case '4' : Consulta(registro);   break;
       case '5' : Relatorio(registro);   break;
       case '6' : bye(); break;
       default  : exit(0);
    }
    getchar();

}

int main()
{
   // system("color 70");
    setlocale(LC_ALL,"Portuguese");



    FILE *doors = fopen("doors.txt","r");
    FILE *registro = fopen("registro.dat","wb+");


    char ch = getc(doors);
    while(ch != EOF)
    {
        putchar(ch);
        ch = getc(doors);
    }
    fclose(doors);

    char in[100];

    printf("\n\n------> Diga amigo, e entre: ");
    scanf("%s",in);
    getchar();

    if(strcmp(in,"Mellon") == 0)
    {
        system("cls");
        FILE *bagend = fopen("bagend.txt","r");

        char ch = getc(bagend);
        while(ch != EOF)
        {
            putchar(ch);
            ch = getc(bagend);
        }
        fclose(bagend);
        printf("\n\t\tVocê é digno! Entre.\n");
        getch();
        Menu(registro);
    }
    else
    {
        system("cls");

        FILE *shall = fopen("shallnot.txt","r");
        char ch = getc(shall);
        while(ch != EOF)
        {
            putchar(ch);
            ch = getc(shall);
        }
        fclose(shall);
        printf("\n\tYOU SHALL NOT PASS!\n");
        printf("\tVocê é indigno! Saia JÁ daqui.\n\n");
        getch();
    }
    fclose(registro);
    return 0;
}
