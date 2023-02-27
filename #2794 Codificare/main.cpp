#include <iostream>
#include <string.h>
using namespace std;

int main()
{
   char s[101],a[101],aux[101],sol[101];
   cin>>s;
   cin>>a;
   if(strlen(s)!=strlen(a))cout<<"cod incorect";
    strcpy(sol,s[1]);//S[1] NU ESTE SIR
   for(int i=1;i<=strlen(s);i++)
   {
       if(a[i]&2==0)
        {
            strcpy(aux,s[i]);//S[i] NU ESTE SIR
            strcpy(aux+strlen(aux),sol);
            strcpy(sol,aux);
        }
        else {strcat(sol,s[i])}//S[i] NU ESTE SIR
   }
   cout<<sol;
}
