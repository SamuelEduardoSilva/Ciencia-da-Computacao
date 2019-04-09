#include<stdio.h>

int main()
{
    int x,y;
    int *px,*py;

    x = 100;
    px = &x;
    py = px;
    y = *py;

    printf("%d %d %d %d\n",*px,*py,px,py);
}
