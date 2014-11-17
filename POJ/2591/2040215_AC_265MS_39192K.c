#include <iostream.h>

#define Max 10000001
int A[Max];
int main()
{
	int N;
	int i,a,b,x,y;
	A[1]=1; a=1; b=1;
	for(i=2; i<Max;i++){
		x=2*A[a]+1;
		y=3*A[b]+1;
		if(x<y){
			A[i]=x;
			a++;
		}
		else if(x>y){
			A[i]=y;
			b++;
		}
		else {
			A[i]=x;
			a++,b++;
		}
	}
	while(scanf("%d",&N)==1)
		printf("%d\n",A[N]);	
	return 0;
}
