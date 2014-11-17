#include<stdio.h>

int n,mary[31000],stt[31000],top;
void slv(){
	int i,j;
	scanf("%d",&n);
	top=1;
	scanf("%d",stt);
	for(i=1;i<n;i++){
		scanf("%d",mary+i);
		if(top%2){
			if(mary[i] > stt[top-1])
				stt[top-1]=mary[i];
			else
				stt[top++]=mary[i];
		} else {
			if(mary[i] < stt[top-1])
				stt[top-1]=mary[i];
			else 
				stt[top++]=mary[i];
		}
	}
	printf("%d\n",top);
}

int main()
{
	int ks; 
	scanf("%d",&ks);
	while(ks--) 
		slv();
}
