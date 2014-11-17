#include <stdio.h>
int A[100001], N,  K;
long long up, low, hlf;
bool enough(long long tm)
{
	long long i, tot=0, tt;
	for(i=1; i<=N; i++) {
		if(A[i] > tm)
		{
			tt=(A[i]-tm+K-1)/K;
			if(tt > tm) return false;
			tot+=tt;
		}
	}
	if(tot > tm) return false;
	return true;
}
int binaryS()
{
	low=0;
	if(K==0) return up;
	while(low < up)
	{
		hlf=(low+up)/2;
		if(enough(hlf))
			up=hlf;
		else
			low=hlf+1;
	}
	return low;
}
int main()
{
	int i;
    scanf("%d", &N);
	for(i=1; i<=N; i++) {
		scanf("%d", A+i);
		if(A[i]>up) up=A[i];
	}
	scanf("%d", &K); K--;
	printf("%d\n", binaryS());
	return 0;
}
