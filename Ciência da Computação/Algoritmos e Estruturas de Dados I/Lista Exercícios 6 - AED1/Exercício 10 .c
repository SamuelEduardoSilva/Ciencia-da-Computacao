#include<stdio.h>
#include<locale.h>

int main(){
   setlocale(LC_ALL,"Portuguese");
   int Gabarito[8];
   int Aluno[10];
   int N1[8];
   int Nota[10]={0,0,0,0,0,0,0,0,0,0};
   int i,j;
   int contAprov=0;
   double Porcent;
   printf("\tPreencha aqui as respostas do gabarito da prova:\n");
   for (i=0;i<8;i++){
    printf("Questão %i: ",i+1);
    scanf("%i",&Gabarito[i]);
   }

   printf("\tDigite aqui o número dos alunos:\n");
   for (i=0;i<10;i++){
     printf("\nAluno %i:\n",i+1);
     scanf("%i",&Aluno[i]);
     for (j=0;j<8;j++){
       printf("Digite a %i° resposta do primeiro aluno: ",j+1);
       scanf("%i",&N1[j]);
       if (N1[j]==Gabarito[j])
        Nota[i]++;
   }
     }

   printf("\n\n");
   printf("Número:\tNota:\n");
   for (i=0;i<10;i++){
    printf("%d\t%d\n",Aluno[i],Nota[i]);
   }
   printf("\n\n");

   for(i=0;i<10;i++){
    if (Nota[i]>=6)
        contAprov++;
   }
   Porcent=(contAprov/10.0)*100;
   printf("A porcentagem de aprovados foi: %.1lf%%\n",Porcent);
}
