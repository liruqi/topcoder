#include<stdio.h>

int n,i,q,a,x,v[1100000];
int main(){
	scanf("%d",&n);
	int sum=0;
	for(i=0;i<n;i++){
		scanf("%d",&q);
		scanf("%d",&a);
		scanf("%d",&x);
		if(a){
			sum+=20;
			if(x)
				sum+=20;
			if(v[q])
				sum+=10;
			v[q]=1;
		}
		else 
			sum+=10;
	}
	printf("%d",sum);
	scanf("%d",&n);
}
