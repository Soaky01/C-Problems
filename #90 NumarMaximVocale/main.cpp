#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream f("vocmax.in");
ofstream g("vocmax.out");
int main()
{
    char s[251],p[251];
    int n,ct,maxim;
    f>>n;
    maxim=0;
    f.get();
    for(int i=1; i<=n; i++)
    {
        ct=0;
        f.getline(s,251);
        for(int j=0; j<strlen(s); j++)
        {
            if(strchr("aeiou",s[j])!=0)ct++;
        }
        if(ct>maxim)
        {
            maxim=ct;
            strcpy(p,s);
        }
    }
    g<<p;
    return 0;

}
