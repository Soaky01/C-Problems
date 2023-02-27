#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream f("medpoz.in");
ofstream g("medpoz.out");
int main()
{
    int n,a[201][201],ct=0,sum=0,ok=0;
    f>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            f>>a[i][j];
        }
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(a[i][j]>0)
            {
                ok=1;
                ct++;
                sum=sum+a[i][j];
            }
        }
    }
    if(ok)
    {
        g << fixed<<setprecision(3)<<(float)sum/ct;
    }
    else g<<"NU EXISTA";

}
