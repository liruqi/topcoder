// in a directed bipartite graph, remove minial edge, so that for each node, either indegree zero or outdegree zero  
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <numeric>
using namespace std;

int C,D,V;

#define MAXV 500
#define DOG (100)
#define ANIMALTYPE(x) ((x) / DOG)
#define ANIMALID(t,x) ((t)*DOG + x)


int res;
int stay[200];

int graph[200][200];
int comb[200][200];
int indegree[200], outdegree[200];


int main() {
    int T;
    cin>>T; 
    // scanf("%d", &T);
    while (T--) {
        cin>>C>>D>>V;
       // scanf("%d %d %d", &C,&D,&V);
        memset(graph, 0, sizeof graph);
        memset(indegree, 0, sizeof indegree);
        memset(outdegree, 0, sizeof outdegree);
        memset(stay, 0, sizeof stay);
        int catLovers = 0;
        int dogLovers = 0;

        for (int i=1; i<=V; i++) {
            string a,b;
            cin>>a>>b;
            int love = ::stoi(a.substr(1)) - 1;
            int hate = ::stoi(b.substr(1)) - 1;
            
            //scanf("%c%d %c%d", buf, &love, buf+1, &hate);
            //printf("#%c %d %c %d\n", a[0], love, b[0], hate);
            int loveani = a[0]-'C';
            int hateani = a[0]-'C';
            int lid = ANIMALID(loveani, love);
            int hid = ANIMALID(hateani, hate);
            graph[lid][hid] += 1;
            outdegree[lid] += 1;
            indegree[hid] += 1;

            if (loveani == 0) catLovers+=1;
            else dogLovers+=1;
        }
        //printf("#cat: %d  dog: %d\n", catLovers, dogLovers);
        res = min(catLovers, dogLovers); // number of unsatisfy
        int remove = 0;
        do {
            memset(comb, 0, sizeof comb);
            int rs, rd, maxcomb = 0;
            for (int c=0; c<C; c++) {
                if (indegree[c]>0 && outdegree[c]>0) {
                    for (int d=0;d<D;d++) {
                        int dogid = d + DOG;
                        if (graph[c][dogid]) {
                            comb[c][dogid] += indegree[c];
                            if (comb[c][dogid] > maxcomb) {
                                rs = c; rd = dogid; maxcomb = comb[c][dogid];
                            }
                        }
                        if (graph[dogid][c]) {
                            comb[dogid][c] += outdegree[c];
                            if (comb[dogid][c] > maxcomb) {
                                rs = dogid; rd = c; maxcomb = comb[dogid][c];
                            }
                        }
                    }
                }
            }
            if (maxcomb==0) break;
            remove += graph[rs][rd];
            graph[rs][rd] = 0;
        } while (1);
        cout<<(V - res)<<endl;
    }
}
