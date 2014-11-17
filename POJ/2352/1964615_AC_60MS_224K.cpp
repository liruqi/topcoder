#include <stdio.h>
int A[65536], cnt[32010];
int main(){
 	int i,n,x,y,num;
 	scanf("%d",&num);
 	for(i=0; i<num; i++){
	 	scanf("%d%d",&x, &y);
	 	if(x==0){
		 	A[0]++;
		 	y = A[0];
		}
	 	else{
		 	n=x;
			for(; n<65536; n += n & (~n + 1))
		  	 	A[n]++;
	        y=0;n=x;
	        while(n>0){
			 	y+=A[n];
				n -= n & (~n + 1);
	    	}
	    	y+=A[0];
		}
	  	cnt[y]++;
    }
    for(i=1; i<=num; i++) printf("%d\n",cnt[i]);
   	return 0;
}

