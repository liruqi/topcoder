#include<stdio.h>
#include<stdlib.h>

#define maxn 1000000
int qua[maxn], con[maxn];
int end;

void add(int a,int c, int p){
    qua[p]=a;
	con[p]=c;
}

void f1()
{
	int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    c=c-a;
	for(b=0;b<end;b++){
        if(qua[b] >= a && con[b] >= c){
            add(a,c,b);
            break;
        }
        else if(qua[b] <= a && con[b] <= c)
            return;
    }
    if(b==end)
        add(a,c,end++);
}

int f(int n,int x)
{
    return qua[n]*x*x + con[n];
}

void f2()
{
    int x,mid,ans,i;
    scanf("%d",&x);
	x++;
	x=abs(x);
    ans=f(0,x);
    for(i=1;i<end;i++)
    {
        mid=f(i,x);
        if(mid<ans)
            ans=mid;
    }
    printf("%d\n",ans);
}

int main()
{
    char mid[2];
    int tc;
    end=0;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",mid);
        if(mid[0]=='I')
            f1();
        else
            f2();
    }
    return 0;
}

