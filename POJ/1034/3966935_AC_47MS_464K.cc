#include <vector>

#include <list>

#include <map>

#include <set>

#include <deque>

#include <stack>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <ctime>

#include <cstring>

using namespace std;



template<class T>

void show(T x){ cout<< "# "<< x <<endl; }

template<class T>

void show(T b,T e){ cout<<"$ "; for(T i=b;i!=e;i++) cout<<*i<<", ";cout<<endl; }



typedef unsigned int uint;

typedef long long ll;

typedef unsigned long long ull;

typedef vector<int> VI;

typedef vector<string> VS;

typedef VI::iterator VII;

typedef VS::iterator VSI;





#define eps 1e-9

#define PI_2 (M_PI*2.0)

#define INF 0X7F7F7F7F

#define ni(x) (scanf("%d", &x))

#define ns(x) (scanf("%s", x))

#define pb push_back

#define sqr(x) ((x)*(x))
/*

  Name: Graph Class

  Copyright: liruqi

  Author: liruqi

  Date: 05-05-08

  Description: a collection for gragh algorithms.

*/



#include <algorithm>

#include <iostream>

#include <vector>

using namespace std;



/*node size*/

const int node_size=110;

const int inf = 0x0f0f0f0f;

typedef vector<int> VI;



/*

in this Graph Class, node are labeled from 1

now I have two methods:

	max match	[OK]

	optimal match	[OK]

*/

//struct MatchGraph{

	bool adj[node_size][node_size];

	bool v_left[node_size],v_right[node_size];

	int match[node_size];

	int left_num,right_num,node_num;

	int weight[node_size][node_size];

	int l_left[node_size],l_right[node_size];

	void init(){

		memset(adj,0,sizeof(adj));

	}

	

	int max_match_dfs(int p){

		int v,t;

		for(v=1;v<=right_num;v++) if(!v_right[v] && adj[p][v]){

			t=match[v];

			v_right[v]=1;

			if(t==0 || max_match_dfs(t)){

				match[v]=p;

				return 1;

			}

		}

		return 0;

	}

	/*

	maximum match

	precodition: 

		weight[][] have been assigned

	*/

	int max_match(){

		int cnt=0;

		memset(match,0,sizeof(match));

		for(int i=1;i<=left_num;i++){

			memset(v_right,0,sizeof(v_right));

			cnt += max_match_dfs(i);

		}

		return cnt;

	}

	

	int min_cover_dfs(int p){

		int v,t;

		v_left[p]=1;

		for(v=1;v<=right_num;v++) if(!v_right[v] && adj[p][v]){

			v_right[v]=1;

			t=match[v];

			if(!v_left[t]){

				min_cover_dfs(t);

			}

		}

	}

	/*

	precondition:

		max match have been found, and matching edge stored in match[]

	postcodition:

		all the visited node are labled with v_left, v_right

		and the min cover node set is all nodes in left which are not labled and in right which are labled

	*/

	void min_cover_nodeset(){

		bool m_left[node_size];

		memset(v_left,0,sizeof(v_left));

		memset(v_right,0,sizeof(v_right));

		memset(m_left,0,sizeof(v_left));

		for(int i=1;i<=right_num;i++)

			if(match[i]){

				m_left[match[i]]=1;

				//m_right[match[i]]=1;

			}

		for(int i=1;i<=left_num;i++)

			if(!m_left[i])//not matched

				min_cover_dfs(i);

		cout<<"left node(s): ";

		for(int i=1;i<=left_num;i++)

			if(!v_left[i])

				cout<<i<<" ";

		cout<<endl;

		cout<<"right node(s): ";

		for(int i=1;i<=right_num;i++)

			if(v_right[i])

				cout<<i<<" ";

		cout<<endl;

	}

	

	int opt_match_dfs(int p){

		int v,t;

		v_left[p]=1;

		for(v=1;v<=right_num;v++)

			if(!v_right[v] && l_left[p]+l_right[v]==weight[p][v]){

				v_right[v]=1;

				t=match[v];

				if(t==0 || opt_match_dfs(t)){

					match[v]=p;

					return 1;

				}

			}

		return 0;

	}

	/*

	optimal match

	precodition: 

		weight[][] have been assigned

	*/

	int opt_match(){

		int i,j,k;

		for(i=1;i<=left_num;i++){

			l_left[i]=-inf;

			for(j=1;j<=right_num;j++)

				if(l_left[i]<weight[i][j])

					l_left[i]=weight[i][j];

		}

		memset(l_right,0,sizeof(l_right));

		memset(match,0,sizeof(match));

		for(k=1;k<=left_num;k++){

			while(1){

				memset(v_left, 0,sizeof(v_left ));

				memset(v_right,0,sizeof(v_right));

				if(opt_match_dfs(k)) break;

				int p=inf;

				for(i=1;i<=left_num;i++)

					if(v_left[i])

						for(j=1;j<=right_num;j++)

							if(!v_right[j]){

								int can=(l_left[i]+l_right[j]-weight[i][j]);

								if(p>can)

									p=can;

							}

				for(i=1;i<=left_num;i++)

					if(v_left[i])

						l_left[i]-=p;

				for(j=1;j<=right_num;j++)

					if(v_right[j])

						l_right[j]+=p;

			}

		}

		int ret=0;

		for(k=1;k<=right_num;k++)

			ret+=weight[match[k]][k];

		return ret;

	}

//} g;




int main(){
	int rp_n;
	ni(rp_n);
	int ip_n;
	ni(ip_n);
	int rp[108][2];
	for(int i=1;i<=rp_n;i++)
	{
		ni( rp[i][0]);
		ni( rp[i][1]);
	}
	
	int ip[108][2];
	for(int i=1;i<=ip_n;i++)
	{
		ni(ip[i][0]);
		ni(ip[i][1]);
	}
	

	left_num= rp_n-1;

	right_num=ip_n;

	
	for(int lt = 1;lt<=left_num;lt++)
		for(int rt=1;rt<=right_num;rt++)
		{
			double d1 = sqrt( sqr(rp[lt][0]-rp[lt+1][0]) + sqr(rp[lt][1]-rp[lt+1][1]) );
			double d2 = sqrt( sqr(rp[lt][0]-ip[rt][0]) + sqr(rp[lt][1]-ip[rt][1]) );
			double d3 = sqrt( sqr(rp[lt+1][0]-ip[rt][0]) + sqr(rp[lt+1][1]-ip[rt][1]) );
			adj[lt][rt] = (d1*2+eps > d2 + d3);
		}
	int add = max_match();
	
	int lmq[108];
	fill(lmq+1, lmq+1+left_num, 0);
	for(int i=1; i<=right_num; i++)
	{
		lmq[ match[i] ] = i;
	}
	cout<< add + rp_n <<endl;
	for(int i=1;i<=left_num;i++)
	{
		cout<<rp[i][0]<<" "<<rp[i][1]<<" ";
		if(lmq[i])
			cout<<ip[ lmq[i] ][0]<<" "<<ip[ lmq[i] ][1]<<" ";
	}
	cout<<rp[rp_n][0]<<" "<<rp[rp_n][1]<<endl;

}
