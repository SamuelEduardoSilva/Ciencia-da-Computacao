#include<stdio.h>
#include<locale.h>
#include<string.h>

int main(){

  char P[20];
  int i;

  printf("Digite a palavra:\n");
  scanf("%20[^\n]",P);

  for(i=0;i<strlen(P);i++)
  {
      if (P[i]=='a'){
         printf("");
      }
      else
         printf("%c",P[i]);
  }
}
