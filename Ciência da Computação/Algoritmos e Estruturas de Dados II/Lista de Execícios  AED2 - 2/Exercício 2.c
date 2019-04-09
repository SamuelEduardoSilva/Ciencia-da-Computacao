#include<stdio.h>
#include<string.h>

int Funtion(char *p1,char *p2,int N)
{
    int i;
    int aux=-1;

    for(i=0;i<N;i++)
    {


        if(*(p1+i)==' ')
        {
            aux=i;
            break;
        }
    }
    for(i=0;i<aux;i++)
    {
       *p2=*p1;
        ++p1;
        ++p2;

    }

    return aux;

}


int main()
{

    char *p1;
    char *p2;
    char x1[10002];
    char x2[10002];

    int N;
    int X;

    scanf("%1000[^\n]",x1);
    getchar();

    p1=&x1;
    p2=&x2;

    N=strlen(p1);
    X=Funtion(p1,p2,N);

    if(X==-1)
        printf("Nao haviam espacos na primeira string\n\n");
    else
    {
        printf("Foram copiados %d caracteres\n",X);
        printf("\nCaracteres copiados:\n");
        int i;
        for(i=0;i<X;i++)
          printf("%c",*(p2+i));
    }
     printf("\n");
}
