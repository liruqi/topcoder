#include <iostream>

using namespace std;

#define maxn 21000


int vst[maxn/100][maxn];
int head, tail;
struct node{
	int u,v,l;
}que[maxn*100]={{0,1,0}};


int N;
bool found;
void tryit(int u,int v,int l){
	if(u*u > N) return;
	if(v > N+(N>>1)) return;
	if(u==N||v==N) {
		found=1;
	}
	if(!vst[u][v]) {
		vst[u][v]=1;
		que[tail].u=u;
		que[tail].v=v;
		que[tail].l=l;
		tail++;
	}
}


int BFS(){
    head=0; tail=1;
    vst[0][1]=1;
	while(head<tail){
		struct node &nd = que[head++];
		int u=nd.u,v=nd.v,l=nd.l+1,t;
		tryit(u,u+v,l);
		tryit(v,u+v,l);
		tryit(u,v<<1,l);
		tryit(u,u<<1,l);
		tryit(v,v<<1,l);
		t=v-u;
		tryit(t,v,l);
		t<u ? tryit(t,u,l):tryit(u,t,l);
		t=(u<<=1);
		t<v ? tryit(t,v,l):tryit(v,t,l);
		
		if(found){
			return l;
		}
	}

}



int main(){

    cin>>N;
	cout<<BFS()<<endl;

    return 0;

}
