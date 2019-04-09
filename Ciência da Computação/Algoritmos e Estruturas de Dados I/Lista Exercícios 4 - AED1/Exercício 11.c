//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int Candidato,cont1=0,cont2=0,cont3=0,cont4=0,contBranco=0,contNulo=0,totalVotos=0;
  float PercentBranco,PercentNulo;
  printf("Opções de voto:\n");
  printf("Canditado 1-(Digite:1)\n");
  printf("Canditado 2-(Digite:2)\n");
  printf("Canditado 3-(Digite:3)\n");
  printf("Canditado 4-(Digite:4)\n");
  printf("Voto branco - (Digite:5)\n");
  printf("Voto nulo - (Digite qualquer número)\n");

  while (printf("Digite seu voto:\n"),scanf("%i",&Candidato),Candidato>0){
    switch (Candidato){
      case 1:
          cont1++;
          break;
      case 2:
          cont2++;
          break;
      case 3:
          cont3++;
          break;
      case 4:
          cont4++;
          break;
      case 5:
           contBranco++;
           break;
      default:
           contNulo++;
    }
    totalVotos++;
  }
  PercentNulo=(contNulo/(float)totalVotos)*100;
  PercentBranco=(contBranco/(float)totalVotos)*100;
  printf("\nTOTAL DE VOTOS:\n");
  printf("Candidato 1 : %i\n",cont1);
  printf("Candidato 2 : %i\n",cont2);
  printf("Candidato 3 : %i\n",cont3);
  printf("Candidato 4 : %i\n",cont4);
  printf("Votos Brancos : %i\n",contBranco);
  printf("Votos Nulos : %i\n",contNulo);
  printf("\nPorcentagem de votos nulos: %.2f%%",PercentNulo);
  printf("\nPorcentagem de votos brancos: %.2f%%",PercentBranco);
}
