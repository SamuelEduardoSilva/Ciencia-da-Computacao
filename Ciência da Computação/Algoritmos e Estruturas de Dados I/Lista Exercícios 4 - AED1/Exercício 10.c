//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  float Salario,mediaSalario,mediaFilhos,maiorSalario=0,Porcent150;
  float somaSalario=0,somaFilhos=0;
  int contSalario=0,contFilhos=0,Filhos,cont150=0,contSal=0;
  while (printf("Digite o sal�rio:R$"),scanf("%f",&Salario),Salario>=0){
    contSalario++;
    somaSalario+=Salario;
    printf("Digite o n�mero de filhos:");
    scanf("%i",&Filhos);
    contFilhos++;
    somaFilhos+=Filhos;
    if  (Salario>maiorSalario)
        maiorSalario=Salario;
    if (Salario<=150.0){
        cont150++;
    }
    contSal++;
  }
  mediaSalario=somaSalario/(float)contSalario;
  mediaFilhos=somaFilhos/(float)contFilhos;
  Porcent150=(cont150/(float)contSal)*100;
  printf("\n\nA m�dia de sal�rios �:R$%.2f\n",mediaSalario);
  printf("A m�dia de filhos �:%.1f\n",mediaFilhos);
  printf("O maior sal�rio �:R$%.2f\n",maiorSalario);
  printf("A porcentagem de pessoas com sal�rio at� R$150.00 �:%.2f%%\n",Porcent150);
}
