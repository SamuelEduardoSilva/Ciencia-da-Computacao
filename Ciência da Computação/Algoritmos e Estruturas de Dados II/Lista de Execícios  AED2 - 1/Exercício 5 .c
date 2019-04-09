#include<stdio.h>

double Total=0;

double Preco(double Divida,int Prestacoes,double Porcentagem,int X)
{
    if(Prestacoes==0)
        return Divida/X;

    double Y=Preco(Divida,Prestacoes-1,Porcentagem,X);
    Total+=Y;
    printf("Prestacao %d = R$%.2lf\n",Prestacoes,Y);
    Y+=Y*(Porcentagem/100);
    return Y;
}


int main()
{
    double Divida;
    int Prestacoes;
    double Porcentagem;
    double Prestac1;
    scanf("%lf %d %lf",&Divida,&Prestacoes,&Porcentagem);
    int X=Prestacoes;
    Preco(Divida,Prestacoes,Porcentagem,X);
    printf("Total = R$%.2lf\n",Total);
}

