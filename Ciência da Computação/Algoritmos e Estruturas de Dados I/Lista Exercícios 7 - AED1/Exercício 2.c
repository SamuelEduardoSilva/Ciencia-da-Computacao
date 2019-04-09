#include<stdio.h>
#include<string.h>
#include<locale.h>
int main(){
  setlocale(LC_ALL,"Portuguese");
  char Nome[50];
  char C;
  int i;
  int X;
  printf("Digite a string:\n");
  scanf("%50[^\n]",Nome);
  getchar();
  printf("Digite o caracter:\n");
  scanf("%c",&C);
   getchar();
  for (i=0;i<strlen(Nome);i++)
  {
      if (Nome[i]==C){
         printf("A posição da primeira ocorrência do caractere na string foi: %d\n",i);
        break;
      }
  }

}
