#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

const int maxn=1000000;

bool vst[maxn];
int fact[10];
int hash(char *x){
	int i,j,r=0,c;
	for(i=1;i<9;i++){
		for(c=j=0;j<i;j++)
		if(x[j]>x[i])
			c++;
		r+=c*fact[i];
	}
	return r;
}

char trace[maxn];

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

char cmd[5]="udlr";

char str[10];

int que[maxn];
int prev[maxn];

int input(){
	int i;
	fact[0]=1;
	for(i=1;i<10;i++)
		fact[i]=i*fact[i-1]; 
    for(i=0;i<9;i++) 
    {
        scanf("%s",str+i);
        if(str[i]=='x') str[i]='0';
    }
}

int valid(int r, int c){
    if(r>2||r<0) return 0;
    if(c>2||c<0) return 0;
    return 1;
}

void print(int p){
	if(prev[p]>0) print(prev[p]);
	putchar(trace[p]);
}

int dfs(){
	int head=0,tail=0,n;
	sscanf(str,"%d",&n);
	prev[tail]=-1;
	que[tail++]=n;
	//vst_insert(n);
	vst[hash(str)]=1;
	while(head<tail){
		n=que[head];
		sprintf(str,(n>100000000?"%d":"0%d"),n);
		int i,p;
		for(p=0;str[p]!='0';p++);//get the position of x
		int r=p/3;
		int c=p%3;
		for(i=0;i<4;i++)
		{
			int rr=r+dir[i][0];
			int cc=c+dir[i][1];
			if(valid(rr,cc)){
				int nt=rr*3+cc;
				swap(str[p],str[nt]);
				sscanf(str,"%d",&n);
				int idx=hash(str);
				if(!vst[idx]){
					trace[tail]=cmd[i];
					que[tail]=n;
					prev[tail]=head;
					if(n==123456780) return tail;
					vst[idx]=1;
					tail++;
				}
				swap(str[p],str[nt]);
			}
		}
		head++;
	}
	printf("%s","unsolvable");
	return 0;
}

int main()
{
	input();
    print( dfs() );
	puts("");
    return 0;
}
