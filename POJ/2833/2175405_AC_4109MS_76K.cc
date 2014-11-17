// puk 2833
#include <stdio.h>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(int x, int y)
	{
		return x>y;
	}
};

int n1, n2, n;
int main()
{
	int i, tp;
	
	while(scanf("%d%d%d", &n1, &n2, &n)!=EOF && n)
	{
		long long sum=0;
		vector<int> V;
		for(i=1; i<=n1 + n2; i++)
		{
			scanf("%d", &tp);
			V.push_back(tp);
		}
		priority_queue<int, vector<int> > maxQ(V.begin(), V.end());		// least n2 
		priority_queue<int, vector<int>, cmp > minQ(V.begin(), V.end());// greatest n1 
		while(maxQ.size() > n2)
		{
			maxQ.pop();
		}
		while(minQ.size() > n1)
		{
			minQ.pop();
		}

		for(; i<=n; i++)
		{
			scanf("%d", &tp);
			if(tp < maxQ.top())
			{
				sum+=maxQ.top();
				maxQ.push(tp);
				maxQ.pop();
			}
			else if(tp > minQ.top())
			{
				sum+=minQ.top();
				minQ.push(tp);
				minQ.pop();
			}
			else
				sum+=tp;
		}
		printf("%.6lf\n", (double)sum/(double)(n-n1-n2));
	}
    return 0;
}
