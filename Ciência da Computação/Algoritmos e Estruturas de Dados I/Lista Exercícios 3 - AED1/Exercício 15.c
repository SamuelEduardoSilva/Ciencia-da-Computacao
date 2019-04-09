//Feito por Samuel Eduardo da Silva
#include<stdio.h>


int main()
{

  int a, b, auxiliar, i, N;


  a = 0;
  b = 1;
  printf("%i\n", a);
  printf("%i\n", b);

  for(i = 2; i <= 45; i++)
  {
    auxiliar = a + b;
     a = b;
    b = auxiliar;

    printf("%i\n", auxiliar);
  }
}

