#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 701

typedef struct point{
	int x,y;
}pit;
pit org[MAXN], rel[MAXN];

bool cmp(pit p,pit q){
	return p.y*q.x<q.y*p.x;
}

int N;
void solve(){
	int j,i,top,res=0;
	for(i=1;i<=N;i++){
		top=1;
		for(j=1;j<=N;j++) if(j!=i){
			rel[top].x = org[j].x-org[i].x;
			rel[top].y = org[j].y-org[i].y;
			int cd=__gcd(rel[top].x, rel[top].y);
			rel[top].x/=cd;
			rel[top].y/=cd;
			if(rel[top].x<0){
				rel[top].x = -rel[top].x;
				rel[top].y = -rel[top].y;
			}
			top++;
		}
		
		sort(rel+1,rel+N,cmp);
		int cpn=1, cur=1;
		for(j=2;j<top;j++) 
			if(rel[j].x==rel[j-1].x && rel[j].y==rel[j-1].y)cur++,cpn>?=cur;
			else cur=1;
		res>?=cpn;
	}
	printf("%d\n", res+1);
}

int main(){
	while(scanf("%d",&N)!=EOF && N>0){
		int i;
		for(i=1;i<=N;i++)
			scanf("%d%d",&org[i].x, &org[i].y);
		solve();
	}
}
