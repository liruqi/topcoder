#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <string>
#include <set>
#include <assert.h>

using namespace std;

#define G_MAX_NODES 26

namespace graph
{
    struct MatrixGraph { // use Adjacency Matrix
        char graph[G_MAX_NODES][G_MAX_NODES];
        int inDegree[G_MAX_NODES];
        
        bool cyclic() { // check if cyclic graph
            return topologicalOrder().size() < G_MAX_NODES;
        }
        
        vector<int> topologicalOrder() {
            memset(inDegree, 0, sizeof(inDegree));
            for (int i=0; i<G_MAX_NODES; i++) {
                for (int j=0; j<G_MAX_NODES; j++) {
                    if(graph[i][j])
                        inDegree[j] += 1;
                }
            }
            
            queue<int> nodes; // can be replace by queue
            vector<int> alp;
            for (int i=0; i<G_MAX_NODES; i++) {
                if (inDegree[i] == 0) nodes.push(i);
            }
            while (nodes.size() > 0) {
                int v = nodes.front();
                nodes.pop();
                alp.push_back(v);
                for (int i=0; i<G_MAX_NODES; i++) {
                    if(graph[v][i]) {
                        graph[v][i] = 0;
                        inDegree[i] -= 1;
                        if (inDegree[i] == 0) {
                            nodes.push(i);
                        }
                    }
                }
            }
            
            return alp;
        }
    };
}

using namespace graph;

struct AlphabetOrderDiv1 : MatrixGraph {

    string isOrdered(vector <string> words) {
        memset(graph, 0, sizeof(graph));
        
        for (int i=0; i<words.size(); i++) {
            string &word = words[i];
            for (int j=0; j+1<word.size(); j++) {
                char left=word[j]-'a'; char right=word[j+1]-'a';
                if (left==right) continue;
                graph[left][right] = 1;
            }
        }
        return cyclic()?"Impossible":"Possible";
    }
};


int main ()
{
    string ws[] = {"xxxxxyeeeemmmpppprrcccwwwwwkkkvvvbbbbbhhqqfuussssaaaaazzziii", "xxyyyeeeemppppppooorccccnnwwkkkkkvvjjjjhhhqqqqqqfffftuddddsssaaaaaaaaggzzzzi", "xempporwwkkvvvvjhhtuuuuddddddagziiiil"};
    vector<string> words(ws, ws+3);
    //    words.push_back("round");
    //    words.push_back("match");
    
    AlphabetOrderDiv1 o;
    cout <<    o.isOrdered(words);
}
