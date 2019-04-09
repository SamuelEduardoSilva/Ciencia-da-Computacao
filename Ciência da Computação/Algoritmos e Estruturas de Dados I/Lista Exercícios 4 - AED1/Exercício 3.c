//Feito por Samuel Eduardo da Silva
#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
  int A,B,cont=0;
  printf("Digite o valor de A:\n");
  scanf("%i",&A);
  printf("Digite o valor de B:\n");
  scanf("%i",&B);
  while (A>=B){
    A=A-B;
    cont++;
  }
  printf("O quociente é:%i\n",cont);
}
