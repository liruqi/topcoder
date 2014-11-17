//Binary Search
#include <stdio.h>

const int maxn=100001;
int A[maxn], N,  K;
long long M, up, low, hlf;

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
	if(tot > tm*M) return false;
	return true;
}

int binaryS()
{
	low=0;
	if(N==0) return 0;
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
	int i, T;
	scanf("%d", &T);
	while(T-- && scanf("%d", &N)!=EOF)
	{
		up=0;
		for(i=1; i<=N; i++) {
			scanf("%d", &A[i]);
			if(A[i]>up) up=A[i];
		}
		scanf("%d%d", &M, &K);
		K--;
		printf("%d\n", binaryS());
	}
	return 0;
}
