#include <iostream>
#include <fstream>
using namespace std;
ifstream f("intervale5.in");
ofstream g("intervale5.out");
int main()
{int a[102]={0},x,y,j,ok=0;
  while(f>>x)
  {
      a[x]++;
  }
  for(int i=0;i<=100;i++)
  {
      /*if(a[i]!=0 && a[i+1]==0){x=i;j=i+1;ok=1;
      while(a[j]==0 && j<=100)
      {
          j=j+1;
      }
      y=j;
      if(y!=101)g<<x<<" "<<y<<endl;}
        */
        if(a[i]!=0)
      {
          for(j=i+1;j<101 && a[j]==0;j++);
          if(j-i>=2 && j<101)
          {g<<i<<" "<<j<<endl;ok=1;}
      }
  }
  if(ok==0)g<<"nu exista";
}
