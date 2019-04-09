#include<stdio.h>
#include<locale.h>
#include<string.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
    char CPF[5][50];
    char Pesquisa[20];
    unsigned long long int Telefone[5];
    char Nome[5][50];
    char Endereco[5][50];
    int i,j=0,t;
    int op;
    printf("*******MENU*******\n\n");
    printf("1 - Cadastramento das informações:\n");
    printf("2 - Pesquisar:\n");
    printf("3 - Sair:\n");
    while (printf("\nDigite a opção desejada: "),scanf("%i",&op),op!=3){
    switch (op){
     case 1:{
         if (j==5)
            printf("Limite máximo de cadastro excedido!\n");

         else{
        printf("\n\tCadastre aqui os dados:\n\n");
        printf("Digite o CPF da %iº pessoa:\n",j+1);
        scanf("%s",&CPF[j]);
        getchar();
        printf("Digite o nome da %iº pessoa:\n",j+1);
        gets(Nome[j]);
        printf("Digite o endereço da %iº pessoa:\n",j+1);
        gets(Endereco[j]);
        printf("Digite o telefone da %iº pessoa:\n",j+1);
        scanf("%lli",&Telefone[j]);
        fflush(stdin);
        printf("\n\n");
        j++;
         }
    }
        break;

     case 2:{
        printf("\nDigite o CPF desejado para pesquisa: ");
        scanf("%s",&Pesquisa);
        getchar();
        printf("\n\nDados do CPF pesquisado:\n");
        for (t=0;t<j;t++){
            if (strcmp (Pesquisa,CPF[t])==0)
            {
                printf("Nome\tTelefone\tCPF\t\tEndereço\n");
                printf("%s\t%lli\t%s\t%s\n",Nome[t],Telefone[t],CPF[t],Endereco[t]);
            }
        }
        break;
     }
     case 3:
        break;
     default:
        printf("Opção inválida:\n");
    }
    }
}


