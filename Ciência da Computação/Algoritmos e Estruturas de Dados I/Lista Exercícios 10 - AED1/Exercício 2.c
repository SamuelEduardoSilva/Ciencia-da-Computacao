#include<stdio.h>
#include<locale.h>
double V;
double PI=3.14;
void Volume(int R)
{
    V=(4/3.0)*PI*(R*R*R);
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int R;
    printf("Digite o raio da esfera:\n");
    scanf("%d",&R);
    Volume(R);
    printf("O volume dessa esfera é: %.2lf\n",V);

    return 0;
}
