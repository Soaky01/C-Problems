#include <iostream>

using namespace std;

int main()
{ int a[101][101],n,m,x,ok=0;
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
          cin>>a[i][j];
      }
    }
    cin>>x;
    for(int i=1;i<=m;i++)
    {  if(a[1][i]==x){ok=1;i=m+1;}
        if(a[n][i]==x){ok=1;i=m+1;}
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i][1]==x){ok=1;i=n+1;}
        if(a[i][m]==x){ok=1;i=n+1;}
    }
    if(ok)cout<<"DA";
    else cout<<"NU";


}
