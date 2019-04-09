#include<stdio.h>
#include<stdlib.h>


typedef struct
{
    int Codigo;
    char email[50];
    int nHoras;

}Registro;


int main()
{

    Registro **x = (Registro **) malloc(10*sizeof(Registro *));
    int i;

    for(i=0;i<10;i++)
    {
        x[i] = (Registro *) malloc(sizeof(Registro));
    }



    printf("Digite os dados dos 10 clientes:\n");
    for(i=0;i<10;i++)
    {
        printf("Cliente %d :\n",i+1);
        printf("Codigo do cliente = ");
        scanf("%d",&x[i]->Codigo);
        printf("E-mail = ");
        scanf("%s",&x[i]->email);
        printf("Total de horas = ");
        scanf("%d",&x[i]->nHoras);
    }
     printf("Relatorio do pagamentos:\n\n");
    for(i=0;i<10;i++)
    {
        printf("Cliente %d :\n",i+1);
        if(x[i]->nHoras>20)
        {
            int aux=x[i]->nHoras-20;
            double total = aux*2.5;
            printf("Total a pagar = R$%.2lf\n",total+35);
        }
        else
            printf("Total a pagar = R$35.00\n");
        printf("\n");
    }
    for(i=0;i<10;i++)
        free(x[i]);
    free(x);


    return 0;
}
