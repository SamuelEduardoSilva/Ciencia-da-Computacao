//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
   float R,C,A,V;
   setlocale(LC_ALL,"Portuguese");
   printf("Digite o valor do raio:\n");
   scanf("%f",&R);
   C=3.14*R;
   A=3.14*(R*R);
   V=4*(3.14*(R*R*R))/3;
   printf("O comprimento dessa esfera é %.2f\n",C);
   printf("A área dessa esfera é %.2f\n",A);
   printf("O volume dessa esfera é %.2f\n",V);
   return 0;

}
