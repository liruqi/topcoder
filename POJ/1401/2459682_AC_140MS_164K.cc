#include <stdio.h>
int n,t,i,out;
int t5[12] = {5,25,125,625,3125,15625,78125,390625,1953125,9765625,
			48828125,244140625};
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		out=0;
		for(i=0;i<12 && t5[i]<=n;i++)
			out += n/t5[i];
		printf("%d\n",out);
	}
	return 0;
}