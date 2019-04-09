// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
   int Idade,MaiorIdade=0,MenorIdade=130,contM=0,contSal=0,IdM;
   char Sexo,SexM;
   double MediaSalario,Salario,TotalSalario,MenorSalario=100000000000;
   printf("Masculino = M | Feminino = F\n\n");
   do{
    printf("Digite a idade:\n");
    scanf("%i",&Idade);
    fflush(stdin);
    if (Idade>=0){
    printf("Digite o sexo:\n");
    scanf("%c",&Sexo);
    getchar();
    printf("Digite o salário:\n");
    scanf("%lf",&Salario);
    fflush(stdin);
    contSal++;
    TotalSalario+=Salario;
    if (Idade>MaiorIdade)
        MaiorIdade=Idade;
    if (Idade<MenorIdade)
        MenorIdade=Idade;
    if (Sexo=='F'&& Salario<=200.0)
        contM++;
    if (Salario<MenorSalario){
        MenorSalario=Salario;
        if (Sexo='F')
            SexM='F';
        else if (Sexo='M')
            SexM='M';
        IdM=Idade;
    }
    }
   }while(Idade>=0);
   MediaSalario=TotalSalario/(double)contSal;
   printf("A media de salários do grupo é:R$%.2lf\n",MediaSalario);
   printf("A maior idade do grupo é: %i , e menor é: %i\n",MaiorIdade,MenorIdade);
   printf("A quantidade de mulheres com salário até R$200.00 é:%i\n",contM);
   printf("A idade e sexo da pessoa que possui menor salário é: %c e %i ,respectivamente.\n",SexM,IdM);
}
