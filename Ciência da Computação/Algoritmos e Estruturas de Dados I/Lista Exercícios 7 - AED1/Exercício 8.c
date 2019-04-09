#include<stdio.h>
#include<string.h>

int main(){

  char N[50];
  char C[50];
  char X[50];
  char v[2]=",";
  printf("Digite o nome:\n");
  scanf("%50[^\n]",N);
  getchar();
  printf("Digite a cidade:\n");
  scanf("%50[^\n]",C);
  getchar();
  printf("Digite o curso:\n");
  scanf("%50[^\n]",X);
  getchar();


  printf("%s\n",strcat(strcat(strcat(strcat(N,v),C),v),X));
}
