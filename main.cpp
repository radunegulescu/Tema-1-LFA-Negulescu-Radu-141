#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream f("f.in");
struct legatura{
    int vec;
    char c;
};
struct noduri{
    legatura leg[100];
    int nrleg=-1;
    bool fin=false;
}v[100];
bool OK=false;
void parcurgere(int curent, int nr, char cuv[100], noduri v[100]){
    if(nr==strlen(cuv)){
        if(v[curent].fin==true)
            OK=true;
    }
    else if(nr<strlen(cuv)){
            for(int i=0;i<=v[curent].nrleg;i++)
                if(v[curent].leg[i].c==cuv[nr])
                    parcurgere(v[curent].leg[i].vec,nr+1,cuv,v);
        }
}
int init,nrfin,nrtranz,i,a,b,x,M;
char l,cuv[100];
int main()
{f>>init>>nrfin;
for (i=0;i<nrfin;i++){
    f>>x;
    v[x].fin=true;
}
f>>nrtranz;
for(i=0;i<nrtranz;i++){
    f>>a>>b>>l;
    v[a].nrleg++;
    v[a].leg[v[a].nrleg].vec=b;
    v[a].leg[v[a].nrleg].c=l;
}
cout<<"cuvant egal= ";
cin.getline(cuv,100,'\n');
if(strcmp(cuv,"lambda")==0)
    if(v[init].fin==true)
        cout<<"valid";
    else
        cout<<"invalid";
else{
    parcurgere(init,0,cuv,v);
    if(OK)
        cout<<"valid";
    else
        cout<<"invalid";
}
}
