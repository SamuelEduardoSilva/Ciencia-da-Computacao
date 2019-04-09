#include<stdio.h>
#include<string.h>


int main()
{
    char S[100];
    int i;

    printf("Digite a string:\n");
    scanf("%100[^\n]",S);

    for(i=0;i<strlen(S);i++)
    {
        if(S[i]=='a')
            printf("*");
        else
            printf("%c",S[i]);
    }
}
