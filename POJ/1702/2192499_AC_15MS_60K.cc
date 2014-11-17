#include <stdio.h>
#include <list>
#include <math.h>
using namespace std;

int pow3[]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,
			 4782969,14348907,43046721,129140163,387420489,1162261467};
int A[20];
int L[20];
int R[20];
int main()
{
	int tc, n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		memset(A, 0, 4*20);
		memset(L, 0, 4*20);
		memset(R, 0, 4*20);
		int len=0;
		while(n){
			A[len]=n%3;
			len++;
			n=n/3;
		}
		int carry=0, i; 
		for(i=0; i<=len; i++)
		{
			A[i]+=carry;
			switch(A[i])
			{
				case 0:
				case 1:
					L[i]=0;
					R[i]=A[i];
					carry=0;
					break;
				case 2:
					L[i]=1;
					R[i]=0;
					carry=1;
					break;
				case 3:
					L[i]=0;
					R[i]=0;
					carry=1;
					break;
			}
		}
		list<int> ll, rl;
		list<int> :: iterator lit;
		int last; 
		for(i=0; i<=len; i++){
			if(L[i])
				ll.push_back(pow3[i]);
		}
		last=*(ll.rbegin());
		if(ll.size() == 0)
			printf("empty ");
		else{
			ll.pop_back();
			for(lit=ll.begin(); lit!=ll.end(); ++lit)
				printf("%d,",*lit);
			printf("%d ", last);
		}

		for(i=0; i<=len; i++){
			if(R[i])
				rl.push_back(pow3[i]);
		}
		last=*(rl.rbegin());
		rl.pop_back();
		for(lit=rl.begin(); lit!=rl.end(); ++lit) 
			printf("%d,",*lit);
		printf("%d\n", last);
	}
	return 0;
}
