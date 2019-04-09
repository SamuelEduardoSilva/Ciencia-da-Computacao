// Feito por Samuel Eduardo da Silva
#include<stdio.h>

int main(){
  int N,i=0,PriMaior=0,SegMaior=0;
  do{
    printf("Digite um valor:\n");
    scanf("%i",&N);
    if (N>PriMaior){
        SegMaior=PriMaior;
        PriMaior=N;
    }
    else if(N>SegMaior||i==0)
     SegMaior=N;
    i++;
  }while(i<10);
  printf("O maior numero digitado foi: %i\n",PriMaior);
  printf("O segundo maior numero digitado foi: %i\n",SegMaior);
}
