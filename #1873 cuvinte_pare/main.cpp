#include <string.h>
#include <iostream>
using namespace std;
char aux[101];
int main()
{
    char s[101], *p;
    int ok=0;
    cin.get(s, 101);
    p = strtok(s, " ");
    while (p)
    {
        if (strlen(p)%2==0)
        {
           strcat(aux,"#");ok=1;
        }
       else strcat(aux,p);
       strcat(aux," ") ;

       p=strtok(NULL," ");
    }
    if(ok==0)cout<<"nu exista";
    else cout<<aux;
    return 0;


}
