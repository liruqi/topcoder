
#include<cstdio>

using namespace std;

const int mx = 100100;


int n,lt_r[mx],rt_r[mx],id[mx],tme,tree[mx*4],lb[mx*4],rb[mx*4],md[mx*4];

struct node{
	int val;
	struct node* next;
} na[mx];
node* adj[mx];
node* top;

void dfs(int s){
	++tme;
	lt_r[s]=tme;
	id[s]=tme;
	for(node* p=adj[s];p;p=p->next)
		if(!id[p->val])
			dfs(p->val);
	rt_r[s]=tme;
}

void ini_tree(int lt,int rt,int idx){
	lb[idx]=lt;
	rb[idx]=rt;
	tree[idx]=(rt-lt+1);
	if(lt>=rt)
		return;
	md[idx]=(lt+rt)/2;
	ini_tree(lt,md[idx],2*idx);
	ini_tree(md[idx]+1,rt,2*idx+1);
}

void tree_update(int p,int idx){
	if(lb[idx]==rb[idx])
	{
		tree[idx]^=1;
		return;
	}
	if(p<=md[idx])
		tree_update(p,2*idx);
	else 
		tree_update(p,2*idx+1);
	tree[idx]=tree[2*idx]+tree[2*idx+1];
}

int tree_query(int lt,int rt,int idx){
	if(lt<=lb[idx] && rt>=rb[idx]){
		return tree[idx];
	}
	int ret=0;
	if(lt<=md[idx]){
		ret+=tree_query(lt,rt,2*idx);
	}
	if(rt>md[idx]){
		ret+=tree_query(lt,rt,2*idx+1);
	}
	return ret;
}

node* add(int v,node* pt){
	top->next = pt;
	top->val = v;
	return top++;
}

int main(){
    int s,t,i,m;
    scanf("%d",&n);
    top=na;
    for(i=n-1;i;i--)
    {
        scanf("%d",&s);
        scanf("%d",&t);
        adj[s] = add(t,adj[s]);
        adj[t] = add(s,adj[t]);
    }
    dfs(1);
    ini_tree(1,n,1);
    scanf("%d",&m);
    char cmd[9];
    for(i=m;i;i--)
    {
        scanf("%s",cmd);
        scanf("%d",&s);
        if(cmd[0]=='C') tree_update(id[s],1);
        else printf("%d\n",tree_query(lt_r[s],rt_r[s],1));
    }
	return 0;
}
