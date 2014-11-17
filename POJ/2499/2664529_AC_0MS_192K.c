//poj 2499

#include<stdio.h>
int left, right;

void gcd(int a, int b){
    if(a*b){
        if(a>b){
            left += a/b;
            a%=b;
            if(a==0) {
                left--;
            }
            gcd(a, b);
        }
        else {
            right += b/a;
            b %= a;
            if(b==0){
                right--;
            }
            gcd(a, b);
        }
    }
}
int main()
{
	int a,b,i,j,t;scanf("%d",&t);
	for(i=1;i<=t;i++){
	   scanf("%d%d",&a,&b);
	   left=right=0;gcd(a,b);
	   printf("Scenario #%d:\n%d %d\n\n",i, left, right);
    }	
	return 0;
}