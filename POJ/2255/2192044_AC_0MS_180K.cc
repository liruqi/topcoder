#include <iostream>
#include <string>
using namespace std;

void prt(string p, string i)
{
    string rt(&p[0],&p[1]);
    int po=i.find(rt);
    if(po > 0)
    {
            string pp(&p[1], &p[po+1]);
            string ii(&i[0], &i[po]);
            prt(pp, ii);
    }
    if(p.length() - po  >1)
    {
            string pp( &p[po+1], &p[p.length()] );
            string ii( &i[po+1], &i[p.length()] );
            prt(pp, ii);
    }
    cout<<i[po];
}

int main()
{
    string P, I;
    while( cin>>P>>I ){
        prt(P,I);
        cout<<endl;
    }
    return 0;    
}
