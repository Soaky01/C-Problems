#include <iostream>

using namespace std;
void factorial(int n,int &f){
    if(n!=0){
        factorial(n-1,f);
        f *=n;
    }
    else f  = 1;
}
int main()
{
    int n,f;
    cin>>n;
    cout<<factorial(n,f);
    return 0;
}
