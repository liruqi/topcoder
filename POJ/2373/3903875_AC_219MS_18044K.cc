

#include<iostream>
#include<string.h>
#include<vector>
#include<set>
#include<algorithm>

#define MAXSZ (1000000+8)
#define pb push_back
using namespace std;
#define ni(x) (scanf("%d",&x))

//typedef vector<int> VI;
//typedef VI::iterator VII;
template<class T>
void show(T b,T e)
{
	for(T i=b;i!=e;i++) cout<<*i<<" ";cout<<endl;
}
	
int cow_n, hill_l, r_max, r_min;
//bool range[MAXSZ];
int dp[MAXSZ], que[MAXSZ], beg[MAXSZ];

/* double list */
int next[MAXSZ], prev[MAXSZ], able[MAXSZ];

void remove(int x)
{
	if(!able[x])
	{
		puts("error: try to remove disable point");
		return ;
	}
	if(next[x]!=-1)
		prev[ next[x] ] = prev[x];
	if(prev[x]!=-1)
		next[ prev[x] ] = next[x];
	able[x] = 0;
	// prev[x] = next[x] = -1;
	// cout<<"remove "<<(x)<<endl;
	// show(next,next+hill_l);
	// show(prev,prev+hill_l);
	/*
	FILE *fp = fopen("info.txt","w");
	fprintf(fp, "remove %d\n", x);
	fclose(fp);
	*/
}

int getnext(int x)
{
	if(able[x])
		return x;
	return next[x] = getnext(next[x]);
}
//end of list ADT

int main()
{
	int stt = clock();
	ni(cow_n);
	ni(hill_l);
	ni(r_min);
	ni(r_max);
	r_max *= 2;
	r_min *= 2;

	int i, st, ed;
	
	memset(next, -1, sizeof(next));
	for(i=0;i<cow_n;i++)
	{
		ni(st);
		ni(ed);
		// start & end point must be even
		if(st%2) st--;
		if(ed%2) ed++;
		if(next[st] < ed) next[st]=ed;
	}
	memset(able, -1, sizeof(able));
	for(st=0;st<=hill_l;)
	{
		if(next[st] == -1)
		{
			next[st] = st+2;
			st+=2;
			continue;
		}
		for(ed=st+2; ed<next[st]; ed+=2)
		{
			if(next[ed]!=-1)
			{
				if(next[st] < next[ed]) next[st]=next[ed];	
			}
			able[ed] = 0;
		}
		for(ed=st+2; ed<next[st]; ed+=2)
			next[ed] = next[st];
		st = ed;
	}
	
	memset(prev, -1, sizeof(prev));
	for(st=0;st<=hill_l;st++)
	{
		if(next[st] != -1)
			prev[ next[st] ] = st;
	}
	// show(next,next+hill_l);
	// show(prev,prev+hill_l);

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	int head=0;
	int tail=1;
	que[0] = 0;
	remove(0);
	while(head<tail)
	{
		st = que[head];
		int p=getnext(st+r_min);
		for(;p<=hill_l && p!=-1 && p-st<=r_max; p=next[(p)])
		{
			if(dp[p] != -1) continue;
			dp[p] = dp[st]+1;
			if(p==hill_l)
			{
				printf("%d\n", dp[hill_l]);
				return 0;
			}
			que[tail++] = p;
			remove(p);
		}
		head++;
	}
	printf("%d\n", dp[hill_l]);
	//FILE *fp = fopen("info.txt","w");
	//fprintf(fp, "Time: %dms\n", clock()-stt);
}
