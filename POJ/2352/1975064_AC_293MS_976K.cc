#include <stdio.h>
#include <iostream>
#define MS 131073				//1>>17
using namespace std;

int A[MS];
int up[MS], low[MS];

//[l, u]->[l, (u+l)/2], [(u+l)/2 + 1, u]
void BuildTree(int l, int u, int p)	
{
	if(p >= MS) {
		//cout<<"Error in BuildTree at "<<p<<endl;
		return ;
	}
	int mid=(l + u) / 2;
	low[p] = l;
	up[p] = u;
	if(l==u) 
		return;
	if(l <= mid)
    	BuildTree(l, mid, 2*p);
	if(mid + 1 <= u)
        BuildTree(mid + 1, u, 2*p + 1);
}

void AddNode(int n, int p)
{
	if(p > MS || low[p] > up[p]) {
		//cout<<"Error in AddNode at "<<p<<endl;
		return ;
	}
    A[p]++;
	if( (low[p]==n) && (up[p]==n) )
		return;
 	if(n <= (low[p] + up[p])/2)
		AddNode(n,2*p);
	else
 		AddNode(n,2*p + 1);
}

int FindSum(int l,int u, int p)
{
 	if(u > up[p] || l<low[p])
 	{
		//cout<<"Error in FindSum at "<<p<<endl;
		return 0;
	}
	if(low[p]==up[p]) 
		return A[p];
	int mid=(low[p]+up[p])/2;
	if(u <= mid)
		return FindSum(l, u, 2*p);
	if(l >= mid+1)
		return FindSum(l, u, 2*p+1);
	if(l==low[p] && u==up[p])
	    return A[p];
	return (FindSum(l,mid, 2*p)+FindSum(mid + 1, u, 2*p+1));
}

int cnt[15010];

void ptree(int n)
{
    if(low[n] > up[n]) 
		return ;
	if(2*n < MS)
		ptree(2*n);
 	if(low[n]+1 <= up[n])
		cout<<A[n]<<" <--> "<<cnt[n]<<endl;
	if(2*n+1 < MS)
		ptree(2*n + 1);
}

int main()
{
	int n,i,x,y;
	BuildTree(0,32000,1);
 	scanf("%d",&n);
 	for(i=0; i<n; i++)
 	{
	 	scanf("%d%d", &x, &y);
        AddNode(x,1);
		y = FindSum(0, x, 1);
		y--;
		cnt[y]++;
	}
 	
 	for(i=0; i<n; i++)
 	{
	    printf("%d\n", cnt[i]);
	}
//	ptree(1);
	cin>>n;
 	return 0;
}

