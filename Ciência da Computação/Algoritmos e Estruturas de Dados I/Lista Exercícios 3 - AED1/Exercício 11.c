//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
main(){
  setlocale(LC_ALL,"Portuguese");
  int i,CPF,Dep;
  double ReM,SalM,ImpR1,Desc1,ImpR2;
  for (i=0;i<10;i++){

  printf("Digite o CPF sem pontos e hífen: ");
  scanf("%i",&CPF);
  printf("Digite o número de dependentes: ");
  scanf("%i",&Dep);
  printf("Digite a renda mensal:R$");
  scanf("%lf",&ReM);
  printf("Digite o salário mínimo atual:R$");
  scanf("%lf",&SalM);

  Desc1=((0.05*SalM)*Dep);
  if (ReM<=(2*SalM))
    printf("Isento!\n");
  else if(ReM<(3*SalM)){
    ImpR1=ReM*0.05;
    ImpR2=ImpR1-Desc1;
    printf("O imposto de renda é: R$%.2lf\n",ImpR2);
  }
  else if(ReM<(5*SalM)){
    ImpR1=ReM*0.10;
    ImpR2=ImpR1-Desc1;
    printf("O imposto de renda é: R$%.2lf",ImpR2);
  }
  else if (ReM<(7*SalM)){
    ImpR1=ReM*0.15;
    ImpR2=ImpR1-Desc1;
    printf("O imposto de renda é: R$%.2lf",ImpR2);
  }
  else if (ReM>(7*SalM)){
    ImpR1=ReM*0.20;
    ImpR2=ImpR1-Desc1;
    printf("O imposto de renda é: R$%.2lf",ImpR2);
  }

}
}
