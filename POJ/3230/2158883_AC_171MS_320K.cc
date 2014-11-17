#include <iostream.h>
const int maxn=100;
int n, m, exp[maxn][maxn], inc[maxn][maxn], A[maxn][maxn];
int maxInc(int day, int cty)
{
	int i, t, mi=A[day-1][1] - exp[1][cty];// + inc[day][cty]
	for(i=2; i<n; i++) //compare cities
	{
		t=A[day-1][i] - exp[i][cty];
		if(t>mi) mi=t;
	}
	return mi+inc[day][cty];
}

int main()
{
	int i, j;
	while(cin>>n>>m && (n+m))
	{
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				cin>>exp[i][j];
		for(i=1; i<=m; i++)
			for(j=1; j<=n; j++)
				cin>>inc[i][j];		
		for(i=1; i<=n; i++)
			A[1][i]=inc[1][i]-exp[1][i];
		for(i=2; i<=m; i++) for(j=1; j<=n; j++)
			A[i][j]=maxInc(i, j);		
		for(i=2; i<=n; i++)
			if(A[m][i]>A[m][1]) 
				A[m][1]=A[m][i];
		cout<<A[m][1]<<endl;
	}
	return 0;
}