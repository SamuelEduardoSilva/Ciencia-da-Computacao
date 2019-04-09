#include<bits/stdc++.h>

using namespace std;

int main()
{

    FILE *table = fopen("tabela.txt","r");


    map<string,char>mapa;
    map<string,char>::iterator it;
    char in[100];
    char out;
    memset(in,0,sizeof(in));

    char a;
    int b = 0;
    a = getc(table);
    in[b++] = a;

    int flag = 0;
    while(a != EOF)
    {

        a = getc(table);
        if(a == '=')
        {
            a = getc(table);
            out = a;
            flag = 1;
        }

        if((a == '0' || a == '1') && flag)
        {
            b = 0;
            mapa[in] = out;
            memset(in,0,sizeof(in));
            flag = 0;


        }
        if(!flag)
            in[b++] = a;

    }
     mapa[in] = out;
     FILE *compactado = fopen("compactado.txt","r");

    char m;
    char compac[100];
    int v = 0;
    memset(compac,0,sizeof(compac));

    m = getc(compactado);
    compac[v++] = m;

    while(m != EOF)
    {
        m = getc(compactado);
        compac[v++]= m;
    }
    string aux = "";

    char descompac[100];
    memset(descompac,0,sizeof(descompac));
    int x = 0;

    for(int i = 0 ; i < v ; i++)
    {

        if(aux != "" && mapa.count(aux))
        {
            descompac[x++] = mapa[aux];
            aux = compac[i];
        }
        else
            aux+=compac[i];
    }
    FILE *descompactado = fopen("descompactado.txt","w");
    fputs(descompac,descompactado);
    fclose(descompactado);

}
