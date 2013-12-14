// in a directed bipartite graph, remove minial edge, so that for each node, either indegree zero or outdegree zero  
#include <iostream>
#include <string>
#include <string.h>
#include <deque>
#include <algorithm>
#include <numeric>
using namespace std;

int C,D,V,S,T;

#define MAXV 500
#define DOG (100)
#define ANIMALTYPE(x) ((x) / DOG)
#define ANIMALID(t,x) ((t)*DOG + x)


int res;

int graph[200][200];
int flow[256][256];
int indegree[200], outdegree[200], level[256];

void addedge(int u,int v,int a,int b) {
    flow[u][v] += a;
    flow[v][u] += a;
}

int bfs() {
    fill(level, level+C+D+2, -1);
    deque<int> Q;
    level[S] = 0;
    Q.push_back(S);
    while(Q.size()) {
        int x=Q.front(); Q.pop_front();
        for (int v=0; v<=T; v++) if(level[v]==-1 && flow[x][v]) {
            level[v] = level[x]+1;
            Q.push_back(v);
        }
    }
    return level[T] != -1;
}

int augmenting(int x,int w) {
    int r=0,t;
    if (x == T) return w;
    for (int v=0;v<=T;v++) if (flow[x][v] && level[v]==level[x]+1) {
        t = flow[x][v];
        if (t + r > w) t = w - r;
        t = augmenting(v, t);
        r += t;
        flow[x][v] -= t;
        flow[v][x] += t;
    }
    if (! r) level[x] = -1;
    return r;
}

int dinic() {
    int r=0,t;
    while (bfs()) {
        while ((t=augmenting(S, 0x7fffffff))) r += t;
    };
    return r;
}

int main() {
    int kase;
    cin>>kase; 
    // scanf("%d", &T);
    while (kase--) {
        cin>>C>>D>>V;
       // scanf("%d %d %d", &C,&D,&V);
        memset(graph, 0, sizeof graph);
        memset(indegree, 0, sizeof indegree);
        memset(outdegree, 0, sizeof outdegree);
        int catLovers = 0;
        int dogLovers = 0;

        for (int i=1; i<=V; i++) {
            string a,b;
            cin>>a>>b;
            int love = ::stoi(a.substr(1)) - 1;
            int hate = ::stoi(b.substr(1)) - 1;
            
            int loveani = a[0]-'C';
            int hateani = b[0]-'C';
            int lid = ANIMALID(loveani, love);
            int hid = ANIMALID(hateani, hate);
            graph[lid][hid] += 1;
            outdegree[lid] += 1;
            indegree[hid] += 1;
            //cout<<"#edge: "<<lid<<hid<<endl;
            if (loveani == 0) catLovers+=1;
            else dogLovers+=1;
        }
        //printf("#cat: %d  dog: %d\n", catLovers, dogLovers);
        // res = min(catLovers, dogLovers); // number of unsatisfy
        // int remove = 0;
        {
            memset(flow, 0, sizeof flow);
            S = C+D;
            T = S+1;
            for (int c=0; c<C; c++) {
                //cout<<"Cat: "<<c+1<<" degree: "<<indegree[c]<<","<<outdegree[c]<<endl;
                    for (int d=0;d<D;d++) {
                        int dogid = d + DOG;
                        int w = graph[c][dogid]; 
                        if (w) {
                            int v = C + d;
                            addedge(c,v,w,0);
                            addedge(S,c,w,0);
                            addedge(S,v,w,0);
                        }
                    }
            }

            for (int d=0; d<D; d++) {
                int dogid = d + DOG;
                    for (int c=0;c<C;c++) {

                        int w = graph[dogid][c];
                        if (w) {
                            int u = C+d;
                            addedge(u,c,w,0);
                            addedge(u,T,w,0);
                            addedge(c,T,w,0);
                        }
                    }
            }
        }
        
        res = dinic();
        cout<<(V - res/2)<<endl;
    }
}
