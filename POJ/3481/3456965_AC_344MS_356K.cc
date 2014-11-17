//poj3481
#define maxn 101
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <list>
#include <cctype>
using namespace std;

struct client {
    int id,pr;
};
struct cmp{
    bool operator()(client p,client q){return p.pr<q.pr;}
};
set<client,cmp> cs;

int main(){
    int cmd,k,p;
    while(scanf("%d",&cmd), cmd){
        switch(cmd){
            case 1:
                scanf("%d",&k);
                scanf("%d",&p);
                cs.insert((client){k,p});
                break;
            case 2:
                if(cs.empty())
                    puts("0");
                else{
                    printf("%d\n",(--cs.end())->id);
                    cs.erase(--cs.end());
                }
                break;
            case 3:
                if(cs.empty())
                    puts("0");
                else{
                    printf("%d\n",(cs.begin())->id);
                    cs.erase(cs.begin());
                }
                break;
        }
    }
}
