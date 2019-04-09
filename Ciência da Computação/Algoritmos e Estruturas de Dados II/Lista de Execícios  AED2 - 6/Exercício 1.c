#include<stdio.h>

void InsertionSort(int vet[], int tam)
{
  int i, j;
  int eleito;
  for (i = 1; i < tam; i++)
  {
    eleito = vet[i];
    j = i - 1;
    while ((j>=0) && (eleito < vet[j]))
    {
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = eleito;
  }
}

int v[10];

int main()
{

    int i;
    int Me;
    int Ma;

    for(i=0;i<10;i++)
         scanf("%d",&v[i]);


    InsertionSort(v,10);

    Me = v[0];
    Ma = v[9];

    int contMa = 0;
    int contMe = 0;

    for(i=0;i<10;i++)
    {
        if(v[i] == Me)
            contMe++;
        else if(v[i] == Ma)
            contMa++;
    }

    printf("Maior numero = %d ,e ele aparece %d vez(es)!\n",Ma,contMa);
    printf("Menor numero = %d ,e ele aparece %d vez(es)!\n",Me,contMe);


}
