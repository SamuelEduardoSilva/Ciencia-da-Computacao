//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
int main(){
  setlocale(LC_ALL,"Portuguese");
  int Canal,Pop,Percent,pop4=0,pop5=0,pop7=0,pop12=0,popTotal=0;
  float Por4,Por5,Por7,Por12;
  while (printf("Digite o canal\n"),scanf("%i",&Canal),Canal!=0){
    printf("Digite o número de pessoas:\n");
    scanf("%i",&Pop);
    switch (Canal){
     case 4:
        pop4+=Pop;
        break;
     case 5:
        pop5+=Pop;
        break;
     case 7:
        pop7+=Pop;
        break;
     case 12:
        pop12+=Pop;
        break;
     default:
        printf("Canal inválido\n");
    }
    if (Canal==4 || Canal==5 || Canal==7 || Canal==12)
    popTotal+=Pop;
  }
  Por4=(pop4/(float)popTotal)*100;
  Por5=(pop5/(float)popTotal)*100;
  Por7=(pop7/(float)popTotal)*100;
  Por12=(pop12/(float)popTotal)*100;
  printf("A porcentagem de audiência do canal 4: %.2f%%\n",Por4);
  printf("A porcentagem de audiência do canal 5: %.2f%%\n",Por5);
  printf("A porcentagem de audiência do canal 7: %.2f%%\n",Por7);
  printf("A porcentagem de audiência do canal 12: %.2f%%\n",Por12);
  return 0;
}
