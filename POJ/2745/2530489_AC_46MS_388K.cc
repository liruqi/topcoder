//team1 lexpegzmmdrp
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef  set<int> sit ;
typedef sit::iterator sii;
const int maxn = 51;
int d[maxn][maxn],n;
int stk[maxn*maxn], top;
sit findsub(sit t, int dep){
    sii it=t.begin();
    int st= *it;
    sit s;
    s.insert(st);
    for(++it; it!=t.end();++it)
        if(dep*2 + d[st][*it] != d[1][st] + d[1][*it])
            s.insert(*it);
    return s;
}

void TravTree(int depth, sit tr){
    //cout<<"tree: ";for(sii it=tr.begin(); it!=tr.end(); ++it) cout<<*it<<" ";cout<<endl;
    //cout<<"depth "<<depth<<endl;
    if(tr.size()<=0) return ;
    //if(depth>n) return ;
    
    int leaf=1, subTree=0;
    sit ln;
    for(sii it=tr.begin(); it!=tr.end(); ++it)
        if(d[1][*it]==depth+1){
            leaf++;
            //cout<<"node "<<*it<<endl;
            ln.insert(*it);
        }
    //cout<<leaf<<endl;
    for(sii it=ln.begin();it!=ln.end(); ++it)
            tr.erase(*it);

    while(tr.size()>0){
        sit sub=findsub(tr,depth);
        //if(!sub.size()) break;
        subTree++;
        for(sii it=sub.begin();it!=sub.end(); ++it)
            tr.erase(*it);
        TravTree(1 + depth, sub);
    }
    //cout<<subTree<<endl;
    stk[top++]=leaf+subTree;
}

int main(){
    int i,j;
    while(cin>>n){
        if(n==0) return 0;
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>d[i][j];
            top=0;
        sit tree;
        for(i=2;i<=n;i++) tree.insert(i);
        TravTree(1,tree);
        sort(stk, stk+top);
        for(i=0;i<top;i++)
            cout<<stk[i]<<(i+1==top?"\n":" ");
    }
    return 0;
}
/*
4
0 2 2 2
2 0 2 2
2 2 0 2
2 2 2 0
2
0 12
12 0
4
0 2 4 4
2 0 4 4
4 4 0 2
4 4 2 0

0
*/
