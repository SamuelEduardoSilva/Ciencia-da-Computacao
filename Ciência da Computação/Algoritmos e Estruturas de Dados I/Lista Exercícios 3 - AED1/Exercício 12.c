//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>
main(){
  setlocale(LC_ALL,"Portuguese");
   int i,Idade,cont5060=0,cont15=0,somaA=0,contRuivoNaoAzul=0,contAzul=0;
   double Peso,Altura,media,PercentAzul;
   char CorOlhos,CorCabelo;
   for (i=0;i<20;i++){
   printf("Digite a idade:\n");
   scanf("%i",&Idade);
   printf("Digite o peso:\n");
   scanf("%lf",&Peso);
   printf("Digite a altura:\n");
   scanf("%lf",&Altura);
   fflush(stdin);
   printf("Digite a cor dos olhos: A-Azul | P-Preto | V-Verde | C-Castanho\n");
   scanf("%c",&CorOlhos);
   fflush(stdin);
   printf("Digite a cor do cabelo: P-Preto | C-Castanho | L-Louro | R-Ruivo\n");
   scanf("%c",&CorCabelo);
   fflush(stdin);
   if (Idade>50 && Peso<60)
    cont5060++;
   if (Altura<1.50){
     cont15++;
     somaA=somaA+Idade;
   }
   if (CorOlhos='A'){
    contAzul++;
   }
   if (CorCabelo='R' && CorOlhos!='A')
        contRuivoNaoAzul++;

}
PercentAzul=(contAzul/20)*100;
printf("A quantidade de pessoas com idade superior a 50 anos , e peso inferior a 60 quilos é : %i",cont5060);
media=somaA/(float)cont15;
printf("A média das idades das pessoas com altura inferior a 1,50 é : %.2lf",media);
printf("A  percentagem de pessoas com olhos azuis entre todas as pessoas analisadas é: %.2lf %%",PercentAzul);
printf("A quantidade de pessoas ruivas e que não possuem olhos azuis é: %i",contRuivoNaoAzul);
}
