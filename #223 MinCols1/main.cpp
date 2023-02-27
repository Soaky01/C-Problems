#include <iostream>
#include <fstream>
using namespace std;
ifstream f("mincols1.in");
ofstream g("mincols1.out");
int main()
{
    int n,a[31][31],ok,prod=1;
    f>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            f>>a[i][j];
        }
    }
     int i=1;
    for(int j=n; j>=1; j--)
    {
        ok=1;
        for(int k=1; k<=n; k++)
        {
            if(a[i][j]>a[k][j])ok=0;
        }
        if(ok){prod=prod*a[i][j];}
        i++;
    }

    g<<prod%10;
}
