#include<stdio.h>

int main(){
	int n,i,j,k,a,b,c,s;
	while(~scanf("%d",&n)){
		s=0;
		for(i=1;i*i*i<=n;i++) if(n%i==0){
			int remain=n/i;//printf("*%d\n",remain);
			for(j=i;j*j<=remain;j++)if(remain%j==0){
				k=remain/j;
				if(i*i+i*j+j*k>s)
				{a=i;b=j;c=k;s=i+j+k;}
			}
		}
		printf("%d %d %d\n",a,b,c);
	}
}