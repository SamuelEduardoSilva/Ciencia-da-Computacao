// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int Sexo,TotF,TotM,TotalIdades=0,Idade,contPessoas=0;
  int contM=0,contF=0;
  float MediaId;
  printf("Sexo Masculino = 0 || Sexo Feminino = 1\n\n");
  do{
  printf("Digite a idade:\n");
  scanf("%i",&Idade);
  if (Idade>0){
  printf("Digite o sexo:\n");
  scanf("%i",&Sexo);
  if (Idade>0 && Sexo==0 || Sexo==1){
  TotalIdades+=Idade;
  contPessoas++;
  }
  if (Sexo==0)
    contM++;
  else if (Sexo==1 && Idade>=30 && Idade<=45)
    contF++;
  }

  }while(Idade>0);
  MediaId=TotalIdades/(float)contPessoas;
  printf("A quantidade de pessoas do sexo masculino foi:%i\n",contM);
  printf("O total de pessoas do sexo feminino com idade entre 30 e 45 inclusive foi:%i\n",contF);
  printf("A media das pessoas é:%.1f",MediaId);
}
