#include<stdio.h>

int main()
{
    char a,b,*p;

    b = 'c';
    p = &a;
    *p = b;

    printf("%c %c %c %c\n",a,b,*p,p);
}
