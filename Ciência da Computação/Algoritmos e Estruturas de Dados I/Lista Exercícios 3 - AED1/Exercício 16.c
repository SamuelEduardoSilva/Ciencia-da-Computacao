//Feito por Samuel Eduardo da Silva
#include <stdio.h>


main() {
    int x, y=1, soma=0, i,cont=0;
    for (i=1;i<100;i++)
    {   y = 1, soma = 0;

            while(i>y)
            {
                if(i%y==0)
                {
                    soma=soma+y;
                }
                y++;
            }
            if(soma==i)
            {
                printf("%i\n", soma);
            }


}}
