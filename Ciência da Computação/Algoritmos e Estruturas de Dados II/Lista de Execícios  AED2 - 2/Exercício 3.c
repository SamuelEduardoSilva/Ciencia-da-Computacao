#include<stdio.h>
#include<string.h>


char Palavras[30][30];
char Frase[30];
int main()
{
    char x;

    int a=0;


    while((x=getch()))
    {
        if(x=='\r')
            break;
         Frase[a++]=x;

    }
    int i;
    int b=0;
    int c=0;
    for(i=0;i<a;i++)
    {
        if(Frase[i]==' ')
        {
            b++;
            c=0;
            continue;

        }
        Palavras[b][c++]=Frase[i];
    }

    printf("Palavras da frase lida:\n\n");

    for(i=0;i<=b;i++)
    {
        printf("%s\n",Palavras[i]);
    }
}
