#include<stdio.h>

void f(int *x,int *y)
{
    int aux = *x-*y;
    *x=*x+*y;
    *y=aux;

}


int main()
{

    int X,Y;

    scanf("%d %d",&X,&Y);

    f(&X,&Y);

    printf("Soma  =  %d\n",X);
    printf("Subtracao = %d\n",Y);

}
// Resposta da quest�o : Por refer�ncia,pois apenas assim para alternar o valor da variavel na fun��o,sem retorno,ou necessidade de declara-las globais.
