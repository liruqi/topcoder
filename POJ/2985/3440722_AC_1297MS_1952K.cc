#include<map>
#include<cstdio>
#define mx 210000
using namespace std;

int n,m,oper,s,t;

map<int,int> ms;
int father[mx],size[mx];

int root(int x){
	int r=x;
	while(father[r]) 
		r=father[r];
	if(r!=x)
		father[x]=r;
	return r;
}

int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	ms[1]=n;
	for(s=1;s<=n;s++) size[s]=1;
	while(m--){
		scanf("%d",&oper);
		if(oper==0){
			scanf("%d",&s);
			scanf("%d",&t);
			int srt=root(s);
			int trt=root(t);
			if(srt!=trt){
				ms[size[srt]+size[trt]]++;
				ms[size[srt]]--;
				ms[size[trt]]--;
				
				father[srt]=trt;
				size[trt]+=size[srt];
				size[srt]=0;
				n--;
			}
		} else {
			scanf("%d",&s);
			s=n-s;
			
			for(map<int,int>::iterator it=ms.begin();it!=ms.end();++it){
				//printf("*set: %d %d s=%d\n",it->first,it->second,s);
				if(s<it->second){
					printf("%d\n",it->first);
					break;
				}
				s-=it->second;
			}
		}
		
	}
}

