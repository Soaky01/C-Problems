/*#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[256],*p,a[101][101],aux[256];
    int k=0;
    int ok;
    cin.get(s,256);
    p=strtok(s," ");
    while(p!=NULL)
    {
        char aux1[256];
        strcpy(aux1,p);
        if(strlen(p)%2!=0)
        {
            strcpy(aux,aux1+strlen(aux1)/2);
            strcpy(aux1+strlen(aux1)/2+1,aux);
        }
        strcpy(a[k],aux1);
        p=strtok(NULL," ");
    }
   ok=0;
    for(int i=1; i<k; i++)
    {
        for(int j=i+1; j<=k; j++)
        {
            if(strcmp(a[i],a[j])==0)
                {
                    i=k;
                    ok=1;
                }
            }
    }
    if(ok)cout<<"DA";
        else cout<<"NU";

}*/
#include <iostream>
#include <string.h>
using namespace std;
int main()
{

    char s[101], *p, a[100][100];
    cin.get(s, 101);
    int c=0;
    p=strtok(s," ");
    int i;
    while (p)
    {

        strcpy(a[c], p); c++;
        p=strtok(NULL, " ");

    }
    for (i=0; i <c; i++)
    {
       strcpy(s,a[i]);
       if (strlen(s) % 2 == 1)
        {

            char s2[100];
            strcpy(s2,s+strlen(s)/2);
            strcpy(s+strlen(s)/2+1,s2);
            int j;

            for (j = 0; j < c; j++)
            {

                if (strcmp(a[j],s) == 0 && i!=j)
                {

                    cout << "DA";

                    return 0;

                }

            }

        }

    }

    cout << "NU";

    return 0;

}
