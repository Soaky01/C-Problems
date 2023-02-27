#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,a[101][101];
    cin>>n;
    cin>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; j++)
        {
            if(i!=n-1 && j!=m-1)
            {
                cout<<a[i][j]<< " ";
            }
        }
        if(i!=n-1)cout<<endl;
    }

    return 0;
}
