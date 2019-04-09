#include<bits/stdc++.h>
#include<locale.h>

using namespace std;

struct node
{
	char sym[10];
	float pro;
	int arr[20];
	int top;
}s[20];

typedef struct node node;


void shannon(int l,int h,node s[])
{
	float pack1=0,pack2=0,diff1=0,diff2=0;
	int i,d,k,j;
	if((l+1)==h || l==h || l>h)
	{
		if(l==h || l>h)
			return;
		s[h].arr[++(s[h].top)]=0;
		s[l].arr[++(s[l].top)]=1;
		return;
	}
	else
	{
		for(i=l;i<=h-1;i++)
			pack1=pack1+s[i].pro;
			pack2=pack2+s[h].pro;
			diff1=pack1-pack2;
		if(diff1< 0)
			diff1=diff1*-1;
		j=2;
		while(j!=h-l+1)
		{
			k=h-j;
			pack1=pack2=0;
			for(i=l;i<=k;i++)
				pack1=pack1+s[i].pro;
			for(i=h;i>k;i--)
				pack2=pack2+s[i].pro;
				diff2=pack1-pack2;
			if(diff2< 0)
				diff2=diff2*-1;
			if(diff2>=diff1)
				break;
			diff1=diff2;
			j++;
		}
		k++;
		for(i=l;i<=k;i++)
			s[i].arr[++(s[i].top)]=1;
		for(i=k+1;i<=h;i++)
			s[i].arr[++(s[i].top)]=0;
		shannon(l,k,s);
		shannon(k+1,h,s);
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

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

	int n,i,j;
	float x,total=0;
	char ch[10];
	node temp;

	printf("Digite quantos caracteres estão presentes no texto: ");
	scanf("%d",&n);

	printf("Digite aqui aqui eles:\n");
	for(i=0;i< n;i++)
	{
		printf("Caracter %d ---> ",i+1);
		scanf("%s",ch);

		strcpy(s[i].sym,ch);
	}

	for(i=0;i< n;i++)
	{
		printf("\nProbabilidade de %s ---> (entre 0.0 e 1.0)\n",s[i].sym);
		scanf("%f",&x);

		s[i].pro=x;
		total=total+s[i].pro;
		if(total>1)
		{
			printf("Essa probabilidade não é possivel. Entre com uma nova:");
			total=total-s[i].pro;
			i--;
		}
	}
	s[i].pro=1-total;
	for(j=1;j<=n-1;j++)
	{
		for(i=0;i< n-1;i++)
		{
			if((s[i].pro)>(s[i+1].pro))
			{
				temp.pro=s[i].pro;
				strcpy(temp.sym,s[i].sym);
				s[i].pro=s[i+1].pro;
				strcpy(s[i].sym,s[i+1].sym);
				s[i+1].pro=temp.pro;
				strcpy(s[i+1].sym,temp.sym);
			}
		}
	}
	for(i=0;i< n;i++)
		s[i].top=-1;

	shannon(0,n-1,s);

	map<string,string>tabela;
	map<string,string>tabela1;

	for(i=n-1;i>=0;i--)
	{
		string aux = "";

		for(j=0;j<=s[i].top;j++)
			aux += (s[i].arr[j] + '0');
		tabela[s[i].sym] = aux;
		tabela[aux] = s[i].sym;
	}

	string compac = "";

	for(int i = 0 ; i < strlen(in); i++)
	{

		string x = "";
		x += in[i];

		compac += tabela[x];
	}

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

    map<string,string>::iterator it1;

    for(it1 = tabela1.begin(); it1 != tabela1.end(); it1++)
    {
        fputs(it1->first.c_str(), table);
        fputs("=",table);
        fputs(it1->second.c_str(),table);
        fputs("\n",table);
    }
    fclose(table);

}
