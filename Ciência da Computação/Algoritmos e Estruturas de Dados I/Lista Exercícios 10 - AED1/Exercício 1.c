#include<stdio.h>
#include<locale.h>
double S2013;
double S2014;
double Percent;
double Dif;

void Per()
{
    Dif=S2014-S2013;
    Percent=(Dif/S2013*100.0);
}
int main()
{
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o sal�rio de 2013: R$");
    scanf("%lf",&S2013);
    printf("Digite o sal�rio de 2014: R$");
    scanf("%lf",&S2014);
    Per();
    printf("\nO percentual de acr�scimo foi d�: %.2lf%%",Percent);

}
