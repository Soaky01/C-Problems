#include <iostream>

using namespace std;

int main()
{
    int n;
    float a[51][51],sum;
    cin>>n;
    for(int i=1; i<=n+1; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==n/2+1)
            {
                a[i][j]=0;
            }
            else cin>>a[i][j];
        }
    }

    for(int j=1; j<=n; j++)
    {sum=0;
        for(int i=1; i<=n+1; i++)
        {
         sum=sum+a[i][j];
        }
        a[n/2+1][j]=sum/n;
    }

    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
