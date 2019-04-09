#include<stdio.h>
#include<string.h>
#include<locale.h>
int main(){
  setlocale(LC_ALL,"Portuguese");
  char Nome[50];
  int N;

  printf("Digite a string:\n");
  scanf("%50[^\n]",Nome);

  printf("Digite o valor de i:\n");
  scanf("%d",&N);

  printf("O i-ésimo caracter da string é: %c",Nome[N]);


}
