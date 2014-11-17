#define mx 1001
int cnt[mx][mx], N, T;

void incy(int x,int y){
	while(y<=N){
		cnt[x][y]++;
		y+=(y&(-y));
	}
}

void inc(int x,int y){
	if(x<1||y<1) 
		return;
	while(x<=N){
		incy(x,y);
		x+=(x&(-x));
	}
}

int ready(int x,int y){
	int ret=0;
	while(y){
		ret += cnt[x][y];
		y-=(y&-y);
	}
	return ret;
}

int read(int x,int y){
	int ret=0;
	while(x){
		ret += ready(x,y);
		x-=(x&(-x));
	}
	return ret;
}

void solve(){
	int x1,x2,y1,y2,x,y;
	char cmd[10];memset(cnt,0,sizeof(cnt));
	while(T--){
	scanf("%s",cmd);
	if(cmd[0]=='C') 
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2),
		inc(x2,y2),inc(x1-1,y2),inc(x2,y1-1),inc(x1-1,y1-1);
	else 
		scanf("%d%d",&x,&y),
		printf("%d\n",(read(N,N)+read(x-1,y-1)-read(x-1,N)-read(N,y-1))&1);
	}puts("");
}

int main(){
	int ks;
	scanf("%d",&ks);
	while(ks--) scanf("%d%d",&N,&T), solve();
}