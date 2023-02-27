
                        //NEEFICIENTA
/*#include <fstream>
using namespace std;

int main()
{
    int x, v[10000],i,n;
    cin>>x;
    v[1]=1;
    for(n=2;;n++)
    {
        if(n%2==0)
            v[n]=v[n-1]+1;
        else
            v[n]=1+2*v[n-2];
        if(v[n]==x) break;
    }
    for(i=n;i>=1;i--)
        cout<<v[i]<<" ";
    return 0;
}*/
                             //EFICIENTA
/*#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int x;
    cin>>x;
    while(x!=1)
    {
        cout<<x<<" ";
        if(x%2==0)
            x--;
        else
            x=(x+1)/2;
    }
    cout<<1;
    return 0;
}*/
                              //RECURSIVA
/*#include <iostream>
#include <fstream>
using namespace std;
int x;
void f(int a,int b,int n)
{
    if(a<=x)
    {
       if(n%2==0)
            f(b,b+1,n+1);
       else
        f(b,1+2*a,n+1);
        cout<<a<<" ";
    }

}
int main()
{

    cin>>x;
    f(1,2,1);
    return 0;
}
*/
