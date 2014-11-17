#include<algorithm>

#define err 0

typedef long long ll;

ll N, k, w;

int top;

struct npair{

	int x,y,w;

}stk[50];

char buf[50], blen;
bool use[50];

bool

cmp(npair p, npair q){

	return p.x<q.x;

}

void 

tryit(ll  ra,ll rb){

	if(ra%2) return;

	ll a=ra/2;

	ll b=rb*10/11-err;

	for(;b+b/10<=rb;b++){

		if(b+b/10==rb) {

			int x=a+b*k;

			int y=a+(b/10)*k;

			if(x+y==N && x>y)

				stk[top++]=(struct npair){x,y,w};

			return;

		}

	}

}



void 

print(int xx,int wi){

	sprintf(buf,"%d",xx);

	blen=strlen(buf);

	while(wi>blen) putchar('0'), wi--;

	printf("%d", xx);

}



int

main(){

	scanf("%I64d",&N);

	for(k=1;k<=N;k*=10, w++){

		ll ra=N%k;

		ll rb=N/k;

		tryit(ra,rb);

		tryit(ra+k,rb-1);

	}

	std::sort(stk,stk+top,cmp);

	int i,cnt=0; 

	for(i=0;i<top;i++) if(i==0 || stk[i].x>stk[i-1].x) use[i]=1,cnt++;
	printf("%d\n",cnt);
	for(i=0;i<top;i++) if(use[i]){

		printf("%d + ",stk[i].x);

		print(stk[i].y,stk[i].w);

		printf(" = %d\n",N);

	}

}
