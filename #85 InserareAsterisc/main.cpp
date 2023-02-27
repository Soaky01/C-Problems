#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char s[101],aux[101];
    int ct=0;
    cin.get(s,101);
    for(int i=0;i<strlen(s);i++)
    {
        if(strchr("aeiou",s[i]))
            {  ct++;
                strcpy(aux,s+i+1);
             strcpy(s+i+2,aux);
             s[i+1]='*';
             i++;
            }
    }
    if(ct==0)cout<<"FARA VOCALE";
    else cout<<s;
}
