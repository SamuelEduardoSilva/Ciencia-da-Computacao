#include<stdio.h>

void ordena(int *a,int *b,int *c)
{
    int maior;
    int menor;
    int intermediario;

    if(*a>*b && *a>*c)
    {
        maior=*a;
        if(*b>*c)
        {
            menor=*c;
            intermediario=*b;
        }
        else
        {
            menor=*b;
            intermediario=*c;
        }
    }

    else if(*b>*c && *b>*a)
    {
        maior=*b;
        if(*a>*c)
        {
            menor=*c;
            intermediario=*a;
        }
        else
        {
            menor=*a;
            intermediario=*c;
        }
    }

    else if(*c > *b && *c > *a)
    {
            maior=*c;
        if(*a>*b)
        {
            menor=*b;
            intermediario=*a;
        }
        else
        {
            menor=*a;
            intermediario=*b;
        }


    }
    *c=maior;
    *a=menor;
    *b=intermediario;
}

int main()
{
    int A,B,C;

    scanf("%d %d %d",&A,&B,&C);

    ordena(&A,&B,&C);

    printf("%d %d %d",A,B,C);
}
