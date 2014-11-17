#include <stdio.h>
#include <stdlib.h>
#define maxn 597801
#define bound 50

typedef struct hashnode{
	int val;
	int cnt;
	struct hashnode *next;
}node;

node *ht[maxn];

int hash(int x){
    x &= 0x7fffffff;
    x %= maxn;
    return x;
}

void hash_insert(int hp, int n){
	node *iter=ht[hp];
	for(; iter!=NULL; iter=iter->next)if(n==iter->val){
		iter->cnt++;
		return;
	}
	iter = (node*)malloc(sizeof(node));
	iter->val=n; iter->cnt=1; iter->next=ht[hp]; 
	ht[hp] = iter;
}

int main(){
    int a1,a2,a3,a4,a5;
    int x1,x2,x3,x4,x5;
    int ps,i,cnt;

    while(5==scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5)) {
        for(i=0;i<maxn; i++)
            ht[i]=NULL;
        
        for(x1=-bound; x1<=bound; x1++)if(x1)
            for(x2=-bound; x2<=bound; x2++)if(x2)
                for(x3=-bound; x3<=bound; x3++)if(x3)
                {
                    ps = (a1*x1)*(x1*x1) + (a2*x2)*(x2*x2) + (a3*x3)*(x3*x3);
        			hash_insert(hash(ps), ps);
                }
        
        cnt = 0;
        for(x4=-bound; x4<=bound; x4++)if(x4)
            for(x5=-bound; x5<=bound; x5++)if(x5)
            {
                ps = (a4*x4)*(x4*x4) + (a5*x5)*(x5*x5);
                ps *= -1;
                node *iter=ht[hash(ps)];
                for(; iter!=NULL; iter=iter->next)
                    if(ps == iter->val){
                        cnt+=iter->cnt;break;
                    }
            }

        printf("%d\n",cnt);
    }
    return 0;
}