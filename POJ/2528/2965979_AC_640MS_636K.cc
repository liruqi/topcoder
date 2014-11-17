/*
2528
Mayor's posters
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 2960		Accepted: 800

Description
The citizens of Bytetown, AB, could not stand that the candidates in the mayoral election campaign have been placing their electoral posters at all places at their whim. The city council has finally decided to build an electoral wall for placing the posters and introduce the following rules:

    * Every candidate can place exactly one poster on the wall.
    * All posters are of the same height equal to the height of the wall; the width of a poster can be any integer number of bytes (byte is the unit of length in Bytetown).
    * The wall is divided into segments and the width of each segment is one byte.
    * Each poster must completely cover a contiguous number of wall segments. 


They have built a wall 10000000 bytes long (such that there is enough place for all candidates). When the electoral campaign was restarted, the candidates were placing their posters on the wall and their posters differed widely in width. Moreover, the candidates started placing their posters on wall segments already occupied by other posters. Everyone in Bytetown was curious whose posters will be visible (entirely or in part) on the last day before elections.
Your task is to find the number of visible posters when all the posters are placed given the information about posters' size, their place and order of placement on the electoral wall.

Input
The first line of input contains a number c giving the number of cases that follow. The first line of data for a single case contains number 1 <= n <= 10000. The subsequent n lines describe the posters in the order in which they were placed. The i-th line among the n lines contains two integer numbers li and ri which are the number of the wall segment occupied by the left end and the right end of the i-th poster, respectively. We know that for each 1 <= i <= n, 1 <= li <= ri <= 10000000. After the i-th poster is placed, it entirely covers all wall segments numbered li, li+1 ,... , ri.

Output
For each input data set print the number of visible posters after all the posters are placed.

The picture below illustrates the case of the sample input.

Sample Input

1
5
1 4
2 6
8 10
3 4
7 10

Sample Output

4
*/
#

#include <cstdio>
#include <list>
#include <cstring>
using namespace std;
const int maxn = 10001;

typedef struct _node{
	int s,e,id;
}node;

node pp[maxn];
bool vs[maxn];
list<node> nl;
typedef list<node>::iterator lii;

void pl(){
	puts("print list:");
	for(lii it=nl.begin(); it!=nl.end(); ++it){
		printf("%d -> %d %d\n",it->s,it->e,it->id);
	}
}

void add(int id){
	int ps=pp[id].s, pe=pp[id].e;
	node nn;
	nn.id=id;
	//pl();
	for(lii it=nl.begin(); it!=nl.end(); ++it){
		if(ps>pe) break;
		if(ps < it->s){
			nn.s=ps;
			nn.e=min(pe,it->s - 1);
			nl.insert(it, nn);
		}
		ps >?= it->e + 1;
	}
	if(ps <= pe){
		nn.s = ps;
		nn.e = pe;
		nl.insert(nl.end(), nn);
	}
}

int main(){
	int n,ks,i;
	scanf("%d",&ks);
	while(ks--){
		nl.clear();
		scanf("%d",&n);
		for(i=n;i;i--){
			scanf("%d%d", &pp[i].s, &pp[i].e);
		}
		for(i=1;i<=n;i++){
			add(i);
		}
		memset(vs,0,maxn);
		for(lii it=nl.begin(); it!=nl.end(); ++it){
			vs[it->id]=1;
		}
		//pl();
		int cnt=0;
		for(i=1;i<=n;i++)
			if(vs[i])
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
