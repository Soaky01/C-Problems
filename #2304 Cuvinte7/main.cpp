#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[21][21],s[401]="";
    int n,k;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    cin>>k;
    for(int i=1; i<=n; i++)
    {
        if(strlen(a[i])==k)
        {
            strcat(s,a[i]);
            strcat(s," ");
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(strlen(a[i])!=k)
        {
            strcat(s,a[i]);
            strcat(s," ");
        }
    }
    cout<<s;

}
