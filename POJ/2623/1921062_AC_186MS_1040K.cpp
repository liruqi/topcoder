#include <cstdio>
#include <algorithm>

using namespace std;
unsigned int a[250001];

int main(void)
{
	int n, p;
	unsigned int P, Q;
	
	scanf("%d", &n);

	for(int i = 1; i <= n; ++i)
		scanf("%u", &a[i]);
	
	if(n % 2)
	{
		p = (n + 1) / 2;
		nth_element(a+1, a+p, a+n+1);
		printf("%u.0\n", a[p]);
	}
	else
	{
		p = n / 2;
		nth_element(a+1, a+p, a+n+1);
		nth_element(a+p+1, a+p+1, a+n+1);
		P = a[p];
		Q = a[p+1];

		if((P + Q) % 2)
			printf("%u.5\n", (P + Q) / 2);
		else
			printf("%u.0\n", (P + Q) / 2);

	}
}
