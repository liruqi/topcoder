//Problem: 2559		User: himdd
//Memory: 1344K		Time: 141MS
//Language: C++		Result: Accepted
//Source Code
#include<iostream>
#include<stdio.h>
using namespace std;
const int A=100005;
struct{
	long long h;
	int id;
}st[A];
long long h[A];
int main()
{
	//freopen("1.txt","r",stdin);
	int n;
	while(scanf("%d",&n),n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&h[i]);
		}
		h[n+1]=0;
		long long ans=0,tmp;
		int top=1;
		st[top].h=h[1];
		st[top].id=1;
		for(int i=2;i<=n+1;i++)
		{
			if(st[top].h>h[i])
			{
				while(top!=0&&st[top].h>h[i])
				{
					tmp=st[top].h*(i-1-st[top].id+1);
                    //st[top].id~i-1的h都是大于等于st[top].h
                    //栈顶元素是序列的最小元素
					if(ans<tmp)
					{
						ans=tmp;
					}
					top--;
				}
				top++;
				st[top].h=h[i];
                //注意这里st[top].id还是原来的id，因为st[top].id~i-1的h都是>h[i]
                //下一次以h[i]为高计算时，st[top].id~i-1也是要加上的。
			}
			else//满足栈单调不减入栈
			{
				top++;
				st[top].h=h[i];
				st[top].id=i;//注意这里的下标还是本来的i
			}
		}
		printf("%lld\n",ans);
	}
}