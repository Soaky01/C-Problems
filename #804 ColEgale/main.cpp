#include <iostream>

using namespace std;

int main()
{
   int a[51][51],n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           cin>>a[i][j];
       }
   }
  int same;
  for(int j=1;j<=m;j++)
  { bool ok=1;int isec=1;
    for(int i=2;i<=n;i++)
    { same = a[isec][j];
      if(a[i][j]!=same)ok=0;
    }
    if(ok)cout<<same<<" ";
    isec++;
  }

   return 0;
}
