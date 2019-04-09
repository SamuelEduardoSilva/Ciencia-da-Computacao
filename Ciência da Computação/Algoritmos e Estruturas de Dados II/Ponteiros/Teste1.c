#include<stdio.h>

int main()
{

    int v1,v2;
    int *p;
    v1 = 5;
    p = &v1;
    v2 = *p;

    printf("%d %d %d\n",v1,v2,*p);
}
