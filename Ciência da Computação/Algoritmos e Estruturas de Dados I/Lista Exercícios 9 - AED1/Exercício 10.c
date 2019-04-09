#include<stdio.h>
#include<locale.h>
#include<stdbool.h>
struct Fun
{
    char Nome[50];
    int Cod;
    int HT;
    int HE;
    double SSH;
    double VH;
    double STT;
    double VHR;
    double PE;
    double PT;
};


int main()
{
    setlocale(LC_ALL,"Portuguese");
    struct Fun X[100];
    int i;
    bool P[100];
    double VHR[100];
    int TH=0;

    for(i=0;i<100;i++)
    {
        printf("%d º - Funcionário:\n",i+1);
        printf("Nome: ");
        scanf("%50[^\n]",X[i].Nome);
        getchar();
        printf("Código: ");
        scanf("%d",&X[i].Cod);
        getchar();
        printf("Horas trabalhadas: ");
        scanf("%d",&X[i].HT);
        getchar();
        X[i].SSH=(X[i].HT * 13.0);
        if(X[i].HT/4 >= 40){
            X[i].HE=X[i].HT-160;
            TH+=X[i].HE;
            P[i]=true;
        }
        else
            P[i]=false;
        X[i].VHR=X[i].HE * (13*0.4);
        X[i].STT=X[i].VHR + X[i].SSH;
        X[i].PE=(X[i].VHR/X[i].STT)*100.0;
        X[i].PT=(X[i].SSH/X[i].STT)*100.0;

    }
    printf("\n\nO total de horas extras trabalhadas foi: %d\n\n",TH);
    printf("Funcionários que receberam horas extras, e os valores recebidos:\n\n");

    for(i=0;i<3;i++)
    {
       if(P[i])
        printf("%s\t\tR$%.2lf\n",X[i].Nome,VHR[i]);
        printf("Salário e percentuais:\n\n");
        printf("R$%2.lf\n",X[i].STT);
        printf("Horas extras: %.1lf\n",X[i].PE);
        printf("Horas trabalhadas: %.1lf\n\n",X[i].PT);



    }

}
