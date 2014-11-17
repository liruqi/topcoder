#include<cstdio>
#include<algorithm>
using namespace std;

int dp[2][8000];
int hook_n, weig_n, hook[24], weig[24];

#define zero 4000
#define ni(x) (scanf("%d",&x))

int main()
{
	ni(hook_n);
	ni(weig_n);
	for(int i=0;i<hook_n;i++)
		ni(hook[i]);
	for(int i=0;i<weig_n;i++)
		ni(weig[i]);
	int left=zero;
	int right = zero;
	dp[1][zero] = 1;
	for(int wid=0;wid<weig_n;wid++)
	{
		int * from = dp[ (wid+1)%2 ];
		int * to = dp[ wid%2 ];
		fill(to, to+8000, 0);
		for(int p=left;p<=right;p++) if(from[p])
		{
			for(int hid=0;hid<hook_n;hid++)
				to[ p+weig[wid]*hook[hid] ]+=from[p];
		}
		left += weig[wid]*hook[0];
		right += weig[wid]*hook[hook_n-1];
	}
	int * from = dp[ (weig_n+1)%2 ];
	printf("%d\n", from[zero]);
}
