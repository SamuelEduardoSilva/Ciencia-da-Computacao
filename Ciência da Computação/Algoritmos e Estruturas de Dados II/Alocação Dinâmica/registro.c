
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
char nome[32];
double peso;
int idade;
}pessoa;
main()
{
pessoa *p;
int i,cont;
printf("Digite o nome da pessoa:\n");
fflush(stdin);
gets(p->nome);
printf("Digite o peso da pessoa:\n");
scanf("%lf",&p->peso);
printf("Digite a idade da pessoa:\n");
scanf("%d",&p->idade);
printf("%s %lf %d\n",p->nome,p->peso,p->idade);
free(p);
system("pause>nul");
}
