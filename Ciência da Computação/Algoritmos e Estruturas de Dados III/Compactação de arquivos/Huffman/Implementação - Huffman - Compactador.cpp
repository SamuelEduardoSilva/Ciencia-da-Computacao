#include<bits/stdc++.h>

using namespace std;

struct MinHeapNo
{
    char dado;
    int frequencia;
    MinHeapNo *esq,*dir;

    MinHeapNo(char d,int f)
    {
        esq = NULL;
        dir = NULL;
        dado = d;
        frequencia = f;
    }

};

struct compare
{
    bool operator()(MinHeapNo *a,MinHeapNo *b)
    {
        return (a->frequencia > b->frequencia);
    }
};

map<string,char>tabela1;
map<char,string>tabela2;

void getTabela(struct MinHeapNo* root, string str)
{
    if (!root)
        return;

    if (root->dado != '#')
    {
        tabela1[str] = root->dado;
        tabela2[root->dado] = str;
    }
    getTabela(root->esq, str + "0");
    getTabela(root->dir, str + "1");
}


MinHeapNo* geraHuffman(char letras[], int freqs[], int tamanho)
{
     MinHeapNo *esq,*dir,*pai;
     priority_queue<MinHeapNo*, vector<MinHeapNo*>, compare> fila;

     for(int i = 0 ; i < tamanho ; i++)
     {
         fila.push(new MinHeapNo(letras[i],freqs[i]));
     }

     while(fila.size() != 1)
     {

         esq = fila.top();
         fila.pop();
         dir = fila.top();
         fila.pop();

         pai = new MinHeapNo('#', esq->frequencia + dir->frequencia);
         pai->esq = esq;
         pai->dir = dir;

         fila.push(pai);

     }
     return fila.top();
}

int main()
{

    FILE *original = fopen("original.txt","r");

    char in[100];
    char a;
    int b = 0;
    memset(in,0,sizeof(in));
    a = getc(original);
    in[b++] = a;

    while(a != EOF)
    {
        a = getc(original);
        in[b++] = a;
    }

    fclose(original);

    map<char,int>mapa;
    map<char,int>::iterator it;

    for(int i = 0 ; i  < strlen(in); i++)
    {
        if(isalpha(in[i]))
        mapa[in[i]]++;
    }
    int v = mapa.size();
    char letras[v];
    int frequencias[v];

    int j = 0;

    for(it = mapa.begin(); it != mapa.end(); it++)
    {
        letras[j] = it->first;
        frequencias[j++] = it->second;
    }
    MinHeapNo *raiz = geraHuffman(letras,frequencias,v);
    getTabela(raiz,"");
    string compac = "";

    for(int i = 0 ; i < strlen(in); i++)
        compac += tabela2[in[i]];

    int cur = 0;
    string f = "";
    char compacFinal[100];

    memset(compacFinal,0,sizeof(compacFinal));
    int q = 0;
    for(int i = 0 ; i < compac.size(); i++)
    {

        if(cur == 8)
        {
            cur = 0;


            long int k = strtol(f.c_str(),0,2);
            f = compac[i];
            compacFinal[q++] = (char)k;
        }
        else
        {
             f+=compac[i];
        }
        cur++;

    }

    long int k = strtol(f.c_str(),0,2);
    compacFinal[q] = char(k);


    FILE *compactado = fopen("compactado.txt","w");
    fputs(compacFinal,compactado);
    fclose(compactado);

    FILE *table = fopen("tabela.txt","w");

    map<string,char>::iterator it1;

    for(it1 = tabela1.begin(); it1 != tabela1.end(); it1++)
    {
        fputs(it1->first.c_str(), table);
        fputs("=",table);
        fputc(it1->second,table);
        fputs("\n",table);
    }
    fclose(table);


}

