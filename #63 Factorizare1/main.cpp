#include <iostream>

using namespace std;

int main()
{
    int n,nrexp=1,ct,d=2,nr;
    cin>>n;
    while(n!=1)
    {ct=0;
        while(n%d==0)
        {
            ct++;
            n=n/d;
        }
        if(ct>=nrexp){nrexp=ct;nr=d;}
        d++;

    }
    cout<<nr;
}
