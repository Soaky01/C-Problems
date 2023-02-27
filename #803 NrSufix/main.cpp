#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nrsufix.in");
ofstream g("nrsufix.out");
int main()
{
    int x,y,ct=0,proc=1,aux=-1,copie;
    f>>x;
    copie=x;
    while(copie!=0)
    {
        copie=copie/10;
         proc=10*proc;
    }

    while(f>>y)
    {
        if(y%proc==x)aux=y;
    }
    if(aux==-1)
        g<<"nu exista";
    else g<<aux;
}
