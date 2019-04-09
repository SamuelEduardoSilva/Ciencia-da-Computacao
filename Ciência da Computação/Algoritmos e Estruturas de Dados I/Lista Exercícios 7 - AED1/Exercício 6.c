#include<stdio.h>
#include<string.h>

int main(){

  char P[100];

  printf("Digite a palavra:\n");
  scanf("%100[^\n]",P);

  printf("_%s_",P);

}
