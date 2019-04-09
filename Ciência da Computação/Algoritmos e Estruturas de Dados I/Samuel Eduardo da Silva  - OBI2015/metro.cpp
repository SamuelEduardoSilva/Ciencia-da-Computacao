//Grafos T.T

#include<iostream>

using namespace std;

int main()
{
    int N,M;
    int i,j;
    cin>>N>>M;
    int cont=0;
    int NX[M];
    int MX[M];

    for(i=0;i<M;i++)
    {
        cin>>NX[i]>>MX[i];
    }
    for(i=0;i<M;i++){
        for(j=0;j<M;j++)
        {
            if(NX[i]==MX[j])
                cont++;
        }
    }
    cout<<cont<<endl;
}
