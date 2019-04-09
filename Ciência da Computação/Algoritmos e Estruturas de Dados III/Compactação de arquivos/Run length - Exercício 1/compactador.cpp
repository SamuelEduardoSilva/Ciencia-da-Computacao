#include<bits/stdc++.h>

using namespace std;

string toBin(int X)
 {
  string aux = "";
  string V;


  while (X>0)
  {
    char C=X%2+'0';
    aux+=C;
    X/=2;
  }
  reverse(aux.begin(),aux.end());

  return aux;
}
int main()
{
    map<char,string>mapa;
    map<string,char>mapa2;

    mapa2["00"] = 'a';
    mapa2["01"] = 'b';
    mapa2["10"] = 'c';
    mapa2["11"] = 'd';

    mapa['a'] = "00";
    mapa['b'] = "01";
    mapa['c'] = "10";
    mapa['d'] = "11";


    FILE *f = fopen("original.txt","r");

    char in[100];
    int a = 0;
    char aux;
    aux = getc(f);
    in[a++] = aux;

    while(aux != EOF)
    {
        aux = getc(f);
        in[a++] = aux;

    }
    int cur = 0;
    string aux1 = "";

    vector<int>vetor;

    int b = 0;


    for(int i = 0; i < strlen(in); i++)
    {
        if(cur != 4)
        {
            aux1 += (mapa[in[i]]);
            cur++;
        }
        else
        {
            vetor.push_back(strtol(aux1.c_str(),0,2));
            cur = 1;
            aux1 = mapa[in[i]];
        }
        if(cur == 4 && i==strlen(in)-1)
           vetor.push_back(strtol(aux1.c_str(),0,2));
    }
    char saida[100];
    memset(saida,0,sizeof(saida));
    int l = 0;

    for(int i = 0 ; i < vetor.size();i++)
    {
        saida[l++] =(char)vetor[i];
    }

    FILE *codificado = fopen("compactado.txt","w");

    fputs(saida,codificado);
    fclose(codificado);

    FILE *compactado = fopen("compactado.txt","r");

    char out[100];
    char aux2;
    a = 0;
    aux2 = getc(compactado);
    out[a++] = aux2;

    while(aux2 != EOF)
    {
        aux2 = getc(compactado);
        out[a++] = aux2;
    }
    char saidaDescompactada[100];
    memset(saidaDescompactada,0,sizeof(saidaDescompactada));
    int k = 0;
    string bin;
    for(int i = 0 ; i < a-1 ; i++)
    {

        bin = toBin((int)out[i]);
        string aux = "";
        int v = bin.size();

        int ans = 8-v;


        for(int  j = 0 ; j < ans ; j++)
            aux+="0";
        aux+=bin;

        int cur = 0;
        string  x = "";
        for(int j = 0 ; j < aux.size(); j++)
        {

            x+=aux[j];
            if(x.size() == 2)
            {
                saidaDescompactada[k++] = mapa2[x];
                x="";
            }
        }


    }
    FILE *descompac = fopen("descompactado.txt","w");
    fputs(saidaDescompactada,descompac);
    fclose(descompac);
}
