#include<stdio.h>
P=1;

void hanoi(int N,char I,char F,char aux)
{

    if (N==1)
    {
        printf("Passo %d  =  move o disco da torre %c para a torre %c\n\n",P,I,F);
        P++;
    }
    else
    {
        hanoi(N-1,I,aux,F);
        printf("Passo %d  =  move o disco da torre %c para a torre %c\n\n",P,I,F);
        P++;
        hanoi(N-1,aux,F,I);
    }
}



int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        if(N%2==0)
           hanoi(N,'A','B','C');
        else
           hanoi(N,'A','C','B');
        P=0;
    }
}
