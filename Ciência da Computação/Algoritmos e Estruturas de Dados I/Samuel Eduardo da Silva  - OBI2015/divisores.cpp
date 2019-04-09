#include<iostream>

using namespace std;

int main()
{
    int N;
    int i,j=0;
    cin>>N;
    for(i=1;i<=N/2;i++)
    {
        if(N%i==0)
            j++;
    }
    cout<<j+1<<endl;
    //+1 pois ele ainda pode ser divisivel por ele mesmo
}
