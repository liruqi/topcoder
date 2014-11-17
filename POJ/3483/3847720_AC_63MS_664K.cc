
/*
Apollo
team4

*/
#include<queue>
#include<cstdio>
#include<algorithm>

using namespace std;

int N,L;

#define ni(x) (scanf("%d",&x))

struct task{
	int val;
	int ddl;
};
struct cmp1{
	bool operator()(task p,task q){
		if(p.val != q.val)
			return p.val<q.val;
		return p.ddl < q.ddl;
	}
};

struct cmp2{
	bool operator()(task p,task q){
		if(p.ddl != q.ddl) return p.ddl < q.ddl;
		return p.val<q.val;
	}
};

task T[10000];

int main()
{
	while(ni(N) != -1)
	{
		ni(L);
		
		for(int i=0;i<N;i++)
		{
			//int val,ddl;
			ni(T[i].val);
			ni(T[i].ddl);
			//pq.push((task){val,ddl});
		}
		sort(T,T+N,cmp2());
		int ret = 0;
		int use = 0;
		int day = T[N-1].ddl;
		int top = N-1;
		priority_queue<task, vector<task>,cmp1> pq;
		while(day >= 0)
		{
			for(; T[top].ddl>=day && top>=0; top--)
				pq.push(T[top]);
			use = L;
			while((use--)>0 && (!pq.empty()))
			{
				ret += pq.top().val;
				//printf("$ %d\n", ret);
				pq.pop();
			}
			day--;
		}
		printf("%d\n", ret);
	}
}

/*
4 1 4 2 1 0 2 0 3 1
7 2
200 1
200 1
100 0
1000 2
80 1
50 20
500 1
0 100
1 0 4 1000


*/
