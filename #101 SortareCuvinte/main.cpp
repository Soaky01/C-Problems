    #include <iostream>
    #include <string.h>
    #include <fstream>
    using namespace std;
    ifstream f("sortcuv.in");
    ofstream g("sortcuv.out");
    int main()
    {
        char s[251],*p,a[250][21],aux[21];
        int n=0;
        f.get(s,251);
        p=strtok(s," ");
        while(p)
        {
            n++;
            strcpy(a[n], p);
            p=strtok(NULL," ");
        }
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
            {
                if(strcmp(a[i],a[j])>0)
                {
                    strcpy(aux,a[i]);
                    strcpy(a[i],a[j]);
                    strcpy(a[j],aux);
                }
            }
            for(int i=1;i<=n;i++)
            {
                g<<a[i]<<endl;
            }


    }
