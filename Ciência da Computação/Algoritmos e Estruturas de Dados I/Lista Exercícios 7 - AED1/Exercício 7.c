#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  char N1[30];
  char N2[30];

  printf("Digite a primeira palavra:\n");
  scanf("%30[^\n]",N1);
  getchar();
  printf("Digite a segunda palavra:\n");
  scanf("%30[^\n]",N2);
  getchar();

  if (strcmp(N1,N2)==0)
    printf("As palavras digitadas s�o iguais!\n");
  else
    printf("AS palavras digitadas n�o s�o iguais!\n");
}
