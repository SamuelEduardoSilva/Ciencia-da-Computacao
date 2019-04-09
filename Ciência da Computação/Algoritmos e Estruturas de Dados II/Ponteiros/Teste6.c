#include<stdio.h>

main()
{
char vet[5]={'0','1','2','3','4'};
char *p;
p = vet;
printf("%c ",vet[4]);
printf("%c",*(p+4));
}
