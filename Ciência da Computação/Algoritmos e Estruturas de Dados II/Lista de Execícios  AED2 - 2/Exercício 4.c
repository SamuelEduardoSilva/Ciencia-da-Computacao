#include<stdio.h>

int main()
{
    int a=10,b,c,d;
    float e,f,g,h;
    char v[10];
    int x;
    int acho=0;

    int *p = &a;

    p++;

    printf("Conteudo do ponteiro = %d\n\n",*p);


    if(p==&b)
        printf("Mesmo endereco que b!\n");
    else if(p==&c)
        printf("Mesmo endereco que c!\n");
    else if(p==&d)
        printf("Mesmo endereco que d!\n");
    else if(p==&e)
        printf("Mesmo endereco que e!\n");
    else if(p==&f)
        printf("Mesmo endereco que f!\n");
    else if(p==&g)
        printf("Mesmo endereco que g!\n");
    else if(p==&h)
        printf("Mesmo endereco que c!\n");
    else if(p==&x)
        printf("Mesmo endereco que x!\n");
    else
    {
        int i=0;
        for(;i<10;i++)
        {
            if(p==&v[i])
            {
                printf("Mesmo endereco que Vet[%d]",i);
                acho=1;
            }

        }
    }
    if(!acho)
        printf("Nenhum endereco correspondeu!\n");



}
