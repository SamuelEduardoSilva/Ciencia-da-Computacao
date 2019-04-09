#include<bits/stdc++.h>

using namespace std;

int Fat(int N)
{
    if(N==0)
        return 1;
    return N*Fat(N-1);
}


int main()
{
    int N;

    while (cin>>N)
    {
        cout<<"Fat("<<N<<") = "<<Fat(N)<<endl;
    }
}
