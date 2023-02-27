#include <iostream>
#include <fstream>
using namespace std;
ifstream f("interclasm.in");
ofstream g("interclasm.out");
int main()
{
    int v[100001],w[100001],x,n,m,i=1,j=1;
    f>>x;
    f>>n;
    while(i<=n)
    {
        f>>v[i++];
    }
    f>>m;
    while(j<=m)
    {
        f>>w[j++];
    }
    i=1;
    j=1;
    while(i<=n && j<=m)
    {
        if(v[i]==w[j])
        {
            i++;
            j++;
        }
            else
                if(v[i]<w[j])
                {
                    if(v[i]%x==0)
                    {
                        g<<v[i++]<<" ";
                    }
                    else i++;
                }

                else
                    if(w[j]%x==0)
                    {
                        g<<w[j++]<<" ";
                    }
                    else j++;
    }
    while(i<=n)
    {
        if(v[i]%x==0)
            g<<v[i]<<" ";
        i++;
    }
    while(j<=m)
    {
        if(w[j]%x==0)
            g<<w[j]<<" ";
        j++;
    }
}
