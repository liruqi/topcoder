#include<stdio.h>
#include<string.h>
using namespace std;
#define mx 2001
#define mq 3000000
int val[mx];

int que[mq], prev[mq], head, tail;
int stk[mx], top;
int main(){
	memset(val,-1,mx*4);
	prev[tail]=-1;
	que[tail]=1;
	tail++;
	val[1]=0;
	
	while(head<tail && tail+10<mq){
		//printf("head=%d tail=%d\n", head, tail);
		int p=head;
		top=0;
		while(p>=0) {
			stk[top++]=que[p];
			p=prev[p];
		}
		int i,j;
		for(i=0;i<top;i++)
		for(j=i;j<top;j++)
		{
			int ty=stk[i]+stk[j];
			if(ty<mx && (val[ty]==-1||val[ty]>=val[que[head]]+1)){
				//printf("add %d\n", ty);
				val[ty]=val[que[head]]+1;
				que[tail]=ty;
				prev[tail]=head;
				tail++;
			}
			ty=stk[i]-stk[j];
			if(ty<0) ty=-ty;
			if(ty>0 && (val[ty]==-1||val[ty]>=val[que[head]]+1)){
				//printf("add %d\n", ty);
				val[ty]=val[que[head]]+1;
				que[tail]=ty;
				prev[tail]=head;
				tail++;
			}
		}//end of add to tail
		head++;
	}

	int ks, n; //scanf("%d",&ks);
	
	
	while(scanf("%d",&n),n) printf("%d\n", val[n]);
}
