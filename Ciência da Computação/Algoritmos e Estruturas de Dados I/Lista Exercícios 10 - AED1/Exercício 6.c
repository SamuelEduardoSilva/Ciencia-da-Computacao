#include<stdio.h>
#include<locale.h>
int Ma;
int Me;
void MaiorMenor()
{
    int N;
    int i;
    for(i=0;i<5;i++)
    {
         printf("Digite o %dº valor:\n",i+1);
         scanf("%d",&N);
         if(i==0){
            Ma=N;
            Me=N;
         }
         else
         {
             if(N>Ma)
                Ma=N;
             else if(N<Me)
                Me=N;
         }
    }
}


int main()
{
    setlocale(LC_ALL,"Portuguese");
    MaiorMenor();
    printf("O maior valor foi: %d\n",Ma);
    printf("O menor valor foi: %d\n",Me);

}
