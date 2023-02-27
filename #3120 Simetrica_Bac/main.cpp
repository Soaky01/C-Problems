#include <iostream>

using namespace std;

int main()
{   int n,m,a[22][22];
    bool ok;
    cin>>m;
    cin>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    ok=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n/2;j++)
        {
            if(a[i][j]!=a[i][n-j+1]){ok=0;i=m+1;}
        }
    }
    if(ok)cout<<"DA";
     else cout<<"NU";
}
