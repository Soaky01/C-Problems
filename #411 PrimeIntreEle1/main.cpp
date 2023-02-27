#include <iostream>

using namespace std;

int main()
{
    int n,c=0,i,j,r;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        for(j=i; j<=n; j++)
        {
            int a,b;
            a=i;
            b=j;
            r=a%b;
            while(r!=0)
            {
                a=b;
                b=r;
                r=a%b;
            }
            if(b==1)c++;

        }

    }
    cout<<c;
}
