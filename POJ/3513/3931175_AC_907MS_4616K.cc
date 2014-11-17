//apollo team4

#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int single, family;

char buf[2008*2008];
#define MAXSZ  100008

typedef vector<int> VI;

VI adj[MAXSZ];

map<string, int> id;
int id_n;
int getid(string &name)
{
	map<string, int>::iterator p=id.find(name);
	if(p == id.end())
	{
		id[name]=(id_n);
		adj[id_n].clear();
		return id_n++;
	}
	return p->second;
}


int que[MAXSZ], head, tail, rootid, ks;
long long exc[MAXSZ], inc[MAXSZ], eT[MAXSZ], iT[MAXSZ];
int rot[MAXSZ], dad[MAXSZ];

template<class T> 
void show(T b, T e)
{
	cout<<"# ";
	for( T i=b;i!=e;i++)cout<<*i<<" ";
	cout<<endl;
}

void solve()
{
	if(single < 0)return;
	fill(rot, rot+id_n, 1);
	for(int s=1;s<id_n;s++)
		for(int i=0;i<adj[s].size();i++)
			rot[ adj[s][i] ] = 0;
	for(int s=1;s<id_n;s++)
		if(rot[s])
			adj[rootid].push_back(s);
	//bfs
	head = tail = 0;
	que[tail++] = rootid;
	dad[rootid] = -1;
	while(head < tail)
	{
		int fid = que[head];
		VI &now = adj[fid];
		for(VI::iterator it=now.begin(); it!=now.end(); ++it)
		{
			que[tail] = *it;
			dad[tail] = head;
			tail++;
		}
		head++;
	}
	//end of bfs
	
	fill(exc, exc+id_n, 0);
	fill(inc, inc+id_n, 0);
	fill(eT,  eT+id_n,  0);
	fill(iT,  iT+id_n,  0);
	
	for(int p=tail-1; p>0; p--)
	{
		//inc[p] = min(exc[p]+single, inc[p]+family);
		int sc = exc[p]+single;
		int fc = inc[p]+family;
		if(sc == fc)
		{
			inc[p] = sc;
			iT [p] = min(iT[p], eT[p])+1;
		}
		else if(sc < fc)
		{
			inc[p] = sc;
			iT[p] = eT[p]+1;
		}
		else if(sc > fc)
		{
			inc[p] = fc;
			iT[p] = iT[p]+1;
		}
		int fid = dad[p];
		if(make_pair(exc[p],eT[p]) > make_pair(inc[p],iT[p]))
		{
		inc[fid] += inc[p];
		iT [fid] += iT [p];
		}
		else 
		{
		inc[fid] += exc[p];
		iT [fid] += eT [p];
		}
		exc[fid] += inc[p];
		eT [fid] += iT [p];
	}
	
	int NF = (exc[rootid] - eT[rootid]*single) / (family - single);
	int NS = eT[rootid] - NF;
	ks++;
	
	cout<<ks<<". "<<NS<<" "<<NF<<" "<<exc[rootid]<<endl;
}



int main()
{
	single = -1;
	string liruqi = "liruqi";
	while(gets(buf))
	{
		string str(buf);
		stringstream ss(str);
		if(isdigit(str[0]))
		{
			solve();
			id.clear();
			id_n = 0;
			ss>>single;
			ss>>family;
			if(single==0 && family==0) break;
			rootid = getid(liruqi);
			
		}
		else 
		{
			string fath, son;
			ss>>fath;
			int fid = getid(fath);
			while(ss>>son)
			{
				adj[fid].push_back( getid(son) );
			}
		}
		
	}
}
