//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
#include<string.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  char Nome[31];
  float P1,P2,P3,P4,P5,PorcentP3;
  int N,i=0,contP3=0;
  printf("Digite o número de alunos da classe:\n");
  scanf("%i",&N);
  fflush(stdin);
  while (i<N){
    printf("\nDigite o nome do aluno: ");
    gets(Nome);

    printf("Digite a nota da matéria 1:");
    scanf("%f",&P1);
    printf("Digite a nota da matéria 2:");
    scanf("%f",&P2);
    printf("Digite a nota da matéria 3:");
    scanf("%f",&P3);
    printf("Digite a nota da matéria 4:");
    scanf("%f",&P4);
    printf("Digite a nota da matéria 5:");
    scanf("%f",&P5);
     fflush(stdin);
    if (P3>=7)
        contP3++;
    if (P1>=7 && P2>=7 && P3>=7 && P4>=7 && P5>=7)
        printf("\nO aluno %s foi aprovado em todas as matérias\n",Nome);
    else if (P1>=7&&P4>=7)
        printf("\nO aluno %s foi aprovado nas matérias 1 e 4\n",Nome);


    i++;
  }
  PorcentP3=(contP3/N)*100.0;
  printf("\nA porcentagem dos aprovados na matéria 3 foi:%.2f%%",PorcentP3);

}
