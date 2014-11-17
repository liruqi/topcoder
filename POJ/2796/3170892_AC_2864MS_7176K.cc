#include<cstdio>
#include<algorithm>
using namespace std;

int N,RMQ[20][100001];
typedef long long ll;
ll S[100001];

int rangemin(int left,int right){
	int k=1, len=right-left+1;
	while((1<<k < len)) k++; k--;
	len=min(RMQ[k][left], RMQ[k][right+1-(1<<k)]);
	return len;
}

int getpos(int now,int dir){
	int li,ri,mi;
	if(dir<0) {
		li=1;
		ri=now;
		while(li<ri){
			mi=(li+ri)/2;
			if(rangemin(mi,now)==RMQ[0][now])
				ri=mi;
			else li=mi+1;
		}
		return li;
	}
	else {
		li=now;
		ri=N;
		while(li<ri){
			mi=(li+ri+1)/2;
			if(rangemin(now,mi)==RMQ[0][now])
				li=mi;
			else ri=mi-1;
		}
		return ri;
	}
}

int main(){
	int i,j;
	while(-1!=scanf("%d",&N)){
		for(i=1;i<=N;i++) scanf("%d",RMQ[0]+i), S[i]=S[i-1]+RMQ[0][i];
		for(j=1;(1<<j)<=N;j++)
			for(i=1;i+(1<<j)<=N+1;i++)
				RMQ[j][i]=min(RMQ[j-1][i], RMQ[j-1][i+(1<<(j-1))]);
		
		ll cur=-1;
		int li,ri,left,right;
		for(i=1;i<=N;i++){
			left = getpos(i,-1);
			right= getpos(i,1);
			ll tmp=(S[right]-S[left-1])*rangemin(left,right);
			if(cur<tmp){
				cur=tmp;
				li=left;
				ri=right;
			}
		}
		printf("%I64d\n%d %d\n",cur,li,ri);
	}
}
