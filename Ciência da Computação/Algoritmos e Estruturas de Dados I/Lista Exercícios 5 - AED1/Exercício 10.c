// Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  double Salario,Ferias,DecimoTerceiro,ResultSalario;
  int OP,Meses;
  printf(">>Menu de op��es<<\n\n");
  printf("1 - Novo Sal�rio\n");
  printf("2 - F�rias\n");
  printf("3 - D�cimo Terceiro\n");
  printf("4 - Sair do programa\n");
  do{
    printf("Digite a op��o desejada:\n");
    scanf("%i",&OP);
    switch (OP){
     case 1:
      printf("Digite o sal�rio:\n");
      scanf("%lf",&Salario);
      if (Salario<210)
        ResultSalario=Salario+(Salario*0.15);
      else if (Salario>=210&&Salario<=600)
        ResultSalario=Salario+(Salario*0.10);
      else if(Salario>600)
        ResultSalario=Salario+(Salario*0.05);
      printf("O novo sal�rio � de:R$%.2lf\n",ResultSalario);
      break;
     case 2:
        printf("Digite o sal�rio:\n");
        scanf("%lf",&Salario);
        Ferias=Salario+(Salario/3);
        printf("O valor das f�rias � de:R$%.2lf\n\n",Ferias);
        break;
     case 3:
        printf("Digite o sal�rio:\n");
        scanf("%lf",&Salario);
        printf("Digite o n�mero de meses trabalhados:\n");
        scanf("%i",&Meses);
        DecimoTerceiro=(Salario*Meses)/12;
        printf("O valor do d�cimo terceiro � de:R$%.2lf\n\n",DecimoTerceiro);
        break;
     case 4:
        break;
     default:
        printf("Op��o inv�lida!\n");

  }
}while(OP!=4);
}
