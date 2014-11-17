//该题求完后缀数组后处理过程效率过低，应该还有优化的余地。

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

using namespace std;

template<class T>
void show(T x){ cout<< "# "<< x <<endl; }
template<class T>
void show(T b,T e){ cout<<"$ "; for(T i=b;i!=e;i++) cout<<*i<<", ";cout<<endl; }

#define MAXSZ 200020 //字符串的最大长度

char str[MAXSZ];

int id[MAXSZ],height[MAXSZ],rank[MAXSZ],next[MAXSZ];

int head,tail,n,t;

bool cmp(const int &i,const int &j){return str[i]<str[j];}
void suffix_sort()
{
	int i,j,k,h;
	for (i=0;i<n;i++) id[i]=i;
	std::sort(id,id+n,cmp);
	for (i=0;i<n;i++)
		if (i==0 || str[id[i]]!=str[id[i-1]]) rank[id[i]]=i;
		else rank[id[i]]=rank[id[i-1]];
	
	for (h=1;h<n;h<<=1) // doubling
	{
		for (i=0;i<n;i++) 
			height[i]=next[i]=-1;
		for (i=n-1;i>=0;i--) if (id[i])
		{
			j=id[i]-h;
			if (j<0) j+=n;
			next[j]=height[rank[j]];
			height[rank[j]]=j;
		}
		j=n-h;
		next[j]=height[rank[j]];
		height[rank[j]]=j;
		for (i=k=0;i<n;i++) if (height[i]>=0)
			for (j=height[i];j>=0;j=next[j]) id[k++]=j;
		for (i=0;i<n;i++)
			if (i>0 && id[i]+h<n && id[i-1]+h<n && rank[id[i]]==rank[id[i-1]] && rank[id[i]+h]==rank[id[i-1]+h]) next[id[i]]=next[id[i-1]];
			else next[id[i]]=i;
		for (i=0;i<n;i++) rank[i]=next[i];
	}
}

void GetHeight()
{
	int i,j,h;
	height[0]=0;
	for (i=0;i<n;i++) rank[id[i]]=i;
	for (h=0,i=0;i<n;i++) if (rank[i]>0)
	{
		j=id[rank[i]-1];
		while (str[i+h]==str[j+h]) ++h;
		height[rank[i]]=h;
		if (h>0) --h;
	}
}

int ST[MAXSZ][20];
void RmqReady()
{
	int i,j;
	for (i=0;i!=n;++i) ST[i][0]=i;
	for (j=1;(1<<j)-1<n;++j)
		for (i=0;i+(1<<j)-1<n;++i){
			if (height[ST[i][j-1]]<height[ST[i+(1<<(j-1))][j-1]])
				ST[i][j]=ST[i][j-1];
			else ST[i][j]=ST[i+(1<<(j-1))][j-1];
		}
}

int GetRmq(int i,int j)
{
	int k=static_cast<int>(floor(log2(j-i+1)));
	if (height[ST[i][k]]<height[ST[j-(1<<k)+1][k]])
		return ST[i][k];
	return ST[j-(1<<k)+1][k];
}

#define sign(x) ((x)==0 ? 0 : ((x)>0 ? 1 : -1))
int main()
{
	scanf("%s", str);
	int len1 = strlen(str);
	str[len1]='#';
	scanf("%s", str+len1+1);
	int len2 = strlen(str+len1+1);
	n = len1 + 1 + len2;
	str[n]='\0';
	
	suffix_sort();
	GetHeight();
	RmqReady();
	int ret = -1;
	for(int i=1;i<n;i++)
		if(height[i] > ret)
			if( sign(id[i-1]-len1)*sign(id[i]-len1) < 0 )
				ret = height[i];
	cout<<(ret)<<endl;
}
