#include <math.h>
int main()
{
	int T,s,e;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&s, &e); e-=s;
		s=sqrt(e);
		while(s*(s+1)>e) s--;
		s=s*2+(e-s*(s+1)+s)/(s+1);
	printf("%d\n",s);
	}
	return 0;
}
