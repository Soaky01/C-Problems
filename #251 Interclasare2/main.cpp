#include <iostream>
#include <fstream>
using namespace std;
ifstream f("interclasare2.in");
ofstream g("interclasare2.out");
int main()
{
    int v[100001],w[100001],n,m,i=1,j=1;
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
    int ct=0;
    i=1;
    j=1;
    while(i<=n && j<=m)
    {
        if(v[i]==w[j])
        {

            g<<v[i++]<<" ";
            ct++;
            j++;
            if(ct%10==0)
            {
                g<<endl;
            }
        }
        else if(v[i]>w[j]) j++;
        else i++;
    }


}
