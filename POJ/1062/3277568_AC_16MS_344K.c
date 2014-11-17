int value[110];
int level[110];
int dgr[110];
int adj[110][110], vld[110], used_level[110];
char vst[110];
int M,N,stk[110],top;

void dfs(int u){
	int v;
	vst[u]=1;
	for(v=1;v<=N;v++)
		if(adj[u][v]!=-1 && !vst[v])
			dfs(v);
	stk[top++]=u;
}

void topological_sort(){
	int i;
	for(i=1;i<=N;i++)
		if(dgr[i]==0)
			dfs(i);
}

int min_cost()
{
	int dp[110], i, j, u, v;
	memcpy(dp, value, sizeof(value));
	for(i=top-1;i>=0;i--){
		u=stk[i];
		if(!vld[u]) continue;
		for(v=1;v<=N;v++)
			if(adj[u][v]!=-1 && vld[v]){
				if(dp[v] > (dp[u]+adj[u][v]))
					dp[v] = (dp[u]+adj[u][v]);
			}
	}
	return dp[1];
}

int main(){
	scanf("%d",&M);
	scanf("%d",&N);
	memset(adj,-1,sizeof(adj));
	int i, j, u;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&value[i]);
		scanf("%d",&level[i]);
		vld[i] = (level[i]-level[1] <= M);
		scanf("%d",&dgr[i]);
		for(j=1;j<=dgr[i];j++) 
		{
			scanf("%d",&u);
			scanf("%d",&adj[u][i]);
		}
	}
	topological_sort();

	int ret = 0x7f7f7f7f;
	for(i=1;i<=N;i++){
		int dif= level[i]-level[1];
		if(dif >=0 && !used_level[dif]){
			used_level[dif]=1;
			memset(vld,0,sizeof(vld));
			for(j=1;j<=N;j++){
				dif = level[i] - level[j];
				if(dif>=0 && dif<=M)
					vld[j]=1;
			}
			u= min_cost();
			if(ret > u) ret=u;
		}
	}
	printf("%d\n", ret);
}