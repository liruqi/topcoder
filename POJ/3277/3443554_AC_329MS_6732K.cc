#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;


const int n_size = 400000;
int lb[n_size],rb[n_size],md[n_size],rt[n_size],ps[n_size],pid[n_size],height[n_size];
typedef long long val_t;
val_t tree[n_size*4];
int n;
int seg(int x){return ps[x+1]-ps[x];}

void init(int lt,int rt,int idx){
	lb[idx]=lt;
	rb[idx]=rt;
	md[idx]=(lt+rt)/2;
	if(lt>=rt)
		return;
	init(lt,md[idx],2*idx);
	init(md[idx]+1,rt,2*idx+1);
}

void tree_update(int lt,int rt,val_t val,int idx){
	if(lb[idx]==lt && rb[idx]==rt)
	{
		tree[idx]>?=val;
		return;
	}
	if(lt<=md[idx])
		tree_update(lt,min(md[idx],rt),val,2*idx);
	if(rt> md[idx])
		tree_update(max(md[idx]+1,lt),rt,val,2*idx+1);
}

val_t tree_query(int idx){
	if(lb[idx] == rb[idx]){
		return seg(lb[idx]) * tree[idx];
	}
	tree[2*idx]>?=tree[idx];
	tree[2*idx+1]>?=tree[idx];
	return tree_query(2*idx)+tree_query(2*idx+1);
}

int get_id(int val){
	int lt=1,rt=n,mid;
	while(lt<rt){
		mid=(lt+rt)/2;
		if(val<ps[mid])
			rt=mid-1;
		else if(val>ps[mid])
			lt=mid+1;
		else {
			return mid;
		}
	}
	return lt;
}

int main(){
	int i;
	scanf("%d",&n);
	n*=2;
	for(int i=0;i<n;i+=2){
		scanf("%d",&rt[i+1]);
		scanf("%d",&rt[i+2]);
		scanf("%d",&height[i]);
	}
	copy(rt+1,rt+n+1,ps+1);
	sort(ps+1,ps+n+1);
	for(int i=1;i<=n;i++){
		pid[i]=get_id(rt[i]);
	}
	init(1,n,1);
	for(int i=0;i<n;i+=2){
		tree_update(pid[i+1], pid[i+2]-1, (val_t)height[i], 1);
	}
	printf("%I64d",tree_query(1));
}
