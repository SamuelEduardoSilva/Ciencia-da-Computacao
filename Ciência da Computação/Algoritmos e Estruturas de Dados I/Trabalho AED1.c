#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<locale.h>
#include<stdlib.h>

int A[10],B[10],Inter[10];
int i;
int a=0;
bool EhPrimo(int X)
{
    int j;

    if(X==2)
        return true;
    else if(X%2==0 || X==1)
        return false;

    else
    {
        for(j=3;j<=sqrt(X);j+=2)
        {
            if(X%j==0)
                return false;
        }
    }
    return true;
}




int procuraPrimo(int W[],int X[])
{
    int x;
    for(x=0;x<10;x++)
    {
        if(EhPrimo(W[x]))
            return W[x];
        else if(EhPrimo(X[x]))
            return X[x];
    }
        return -1000;

}

void calcularInterseccao(int Y[],int X[])
{
    int j;
    int b;
    a=0;
   printf("Vetor Intersec��o:\n");
    for(j=0;j<10;j++)
    {

            if(Y[j]==X[j])
            {
                Inter[a]=Y[j];
                a++;
                printf("Inter[%d] = %d\n",a-1,Inter[a-1]);
            }

        }
    }



void Printa(void)
{

    int l,j,k;
    printf("\nVetor A:\n");
    for(l=0;l<10;l++)
    {
        printf("A[%d] = %d\n",l,A[l]);
    }
    printf("\n");
    printf("Vetor B:\n");
    for(l=0;l<10;l++)
    {
        printf("B[%d] = %d\n",l,B[l]);
    }
    if(a>0)
    {
        printf("\n");
    printf("Intersec��o:\n");
    for(l=0;l<a;l++)
    {
        printf("Inter[%d] = %d\n",l,Inter[l]);
    }
    }
    else printf("Intersec��o n�o calculada ou vazia!\n");
}
int incrementaValor(int a,int b)
{
    int l;
    int cont=0;
   for (l=0;l<10;l++)
   {
       if(A[l]==a)
       {
           A[l]+=b;
           cont++;
       }

       if(B[l]==a)
       {
           B[l]+=b;
           cont++;
       }

   }

    return cont;
}

main(){

    setlocale(LC_ALL,"Portuguese");
system("color F0");
    int recebePrimo,recebeIncrementos,op;
    int N;
    int In;
    printf("Preencha o vetor A de 10 posi��es:\n");
    for(i=0;i<10;i++){
        scanf("%d",&A[i]);
    }

    printf("\nPreencha o vetor B de 10 posi��es:\n");
    for(i=0;i<10;i++){
        scanf("%d",&B[i]);
    }
    while(op!=5)
    {

    printf("\n\nEscolha uma op��o:\n");
    printf("\n1 - Procura n�mero primo\n");
    printf("2 - Calcular vetor intersec��o\n");
    printf("3 - Incrementa valor espec�fico\n");
    printf("4 - Imprimir na tela\n");
    printf("5 - Sair\n\n");

    scanf("%d",&op);

    switch(op){
case 1:
    recebePrimo=procuraPrimo(A,B);
    if(recebePrimo!=-1000)
    {
    printf("O primeiro n�mero primo encontrado foi: ");
    printf("%d\n\n",recebePrimo);
    }
    else printf("\nNenhum primo foi encontrado!\n\n");

    break;
case 2:
    calcularInterseccao(A,B);
    break;
case 3:
    printf("Entre com o numero a ser procurado: ");
    scanf("%d",&N);
    printf("Entre com o valor a ser incrementado: ");
    scanf("%d",&In);
    recebeIncrementos=incrementaValor(N,In);
    printf("Quantidade de vezes incrementadas: %d\n",recebeIncrementos);
    break;
case 4:
    Printa();
    break;
case 5:
    break;
default:
    printf("\nOp��o inv�lida! Escolha outra op��o.\n");
    }

    }

}
