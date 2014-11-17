#include<stdio.h>
#include<string.h>
#define maxn 210
#define maxsum 2000000000

struct node
{
	int max;
	int f;
}
map[maxn][maxn];

int pre[maxn];
int v[maxn];
int q[maxn*maxn];

int n,m;

void sc()
{
	int i,n1,n2,max;
	memset(map,0,sizeof(map));
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&n1,&n2,&max);
		map[n1-1][n2-1].max+=max;
	}
}

int solve()
{
	int s=0,t=m-1,i;
	while(1)
	{
		int head=1,end=0;
		memset(pre,0xff,sizeof(pre));
		v[s]=maxsum;
		q[0]=s;
		pre[s]=s;
		while(head>end&&pre[t]==-1)
		{
			int mid=q[end++];
			for(i=0;i<m;i++)
			if(pre[i]==-1)
			{
				if(map[mid][i].max>map[mid][i].f)
				{
					q[head++]=i;
					pre[i]=mid;
					v[i]=(v[mid]>map[mid][i].max-map[mid][i].f?map[mid][i].max-map[mid][i].f:v[mid]);
				}
				else if(map[i][mid].f>0)
				{
					q[head++]=i;
					pre[i]=-mid;
					v[i]=(v[mid]>map[i][mid].f?map[i][mid].f:v[mid]);
				}
			}
		}
		if(pre[t]==-1)
			break;
		i=t;
		while(i!=s)
		{
			int mid=pre[i];
			if(mid>=0)
				map[mid][i].f+=v[t];
			else
				map[i][-mid].f-=v[t];
			i=mid;
			if(i<0)
				i=-i;
		}
	}
	int ans=0;
	for(i=1;i<m;i++)
		ans+=map[s][i].f;
	return ans;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		sc();
		printf("%d\n",solve());
	}
	return 0;
}
