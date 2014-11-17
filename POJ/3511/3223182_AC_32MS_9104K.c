#define mx 1000000
char p[mx];
int cx[mx];
int cy[mx];

int main(){
	int i,j;
	memset(p,1,sizeof(p));
	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	p[0]=p[1]=0;
	for(i=2;(j=i*i)<mx;i++)
		for(;j<mx;j+=i)
			p[j]=0;
	for(i=2;i<mx;i++){
		if(p[i]){
			cx[i]=1;
			if(i==2 || i%4 == 1) cy[i]=1;
		}
		cx[i]+=cx[i-1];
		cy[i]+=cy[i-1];
	}
	int l,u,x,y;
	while(scanf("%d%d",&x,&y) && ((~x)||(~y))){
		l=x; if(x<1) l=1;
		u=y; if(y<1) u=1;
		printf("%d %d %d %d\n",x,y,cx[u]-cx[l-1],cy[u]-cy[l-1]);
	}
}
