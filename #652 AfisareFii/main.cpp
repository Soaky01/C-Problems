#include <iostream>
#include <fstream>
using namespace std;
ifstream f("afisarefii.in");
ofstream g("afisarefii.out");
int nrfii(int n,int v[100],int x)
{int ct=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==x)ct++;
    }
    return ct;
}
void afisarefii(int n,int v[100],int x)
{
    for(int i=1;i<=n;i++)
    {
        if(v[i]==x)g<<i<<" ";
    }
}

int main()
{
    int v[100],i,n,k,x;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
    }
    f>>k;
    for(i=1;i<=k;i++)
    {
        f>>x;
        g<<nrfii(n,v,x)<<" ";
        afisarefii(n,v,x);
        g<<endl;
    }
}
