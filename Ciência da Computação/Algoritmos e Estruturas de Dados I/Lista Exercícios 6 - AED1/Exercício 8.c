#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  char Nome[5][50];
  double N1[5],N2[5];
  double MediaC,SomaM=0,Media[5];
  int i;
  int contA=0,contR=0;
  int op;
  for (i=0;i<5;i++){
    printf("Digite o nome do aluno:\n");
    scanf("%s",&Nome[i]);
    getchar();
    printf("Digite a nota da prova 1 desse aluno:\n");
    scanf("%lf",&N1[i]);
    printf("Digite a nota da prova 2 desse aluno:\n");
    scanf("%lf",&N2[i]);
    Media[i]=(N1[i]+N2[i])/2.0;
    SomaM+=Media[i];
  }
  printf("\n\tRelatório de notas:\n\n");
  printf("Aluno\tProva 1\tProva 2\tMédia\tSituação\n");
  for (i=0;i<5;i++){
  printf("%s",Nome[i]);
  printf("\t%.1lf\t%.1lf\t%.1lf\t",N1[i],N2[i],Media[i]);
  if (Media[i]>=7.0){
    printf("Aprovado\n");
    contA++;
  }
  else{
    printf("Reprovado\n");
    contR++;
  }
  }
  MediaC=SomaM/5;
  printf("\n\n\tA média da classe é:%.1lf\n",MediaC);
  printf("\tA quantidade de aprovados foi: %i\n",contA);
  printf("\tA quantidade de reprovados foi: %i\n",contR);
}
