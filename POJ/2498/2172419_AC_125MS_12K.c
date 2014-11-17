#include <stdio.h>
#include <string.h>
int F[3]={9, 3 ,7};
char id[9];
int sum;
int main()
{
	int i, j, T, que, len;scanf("%d", &T);
	for(i=1; i<=T; i++){
		scanf("%s", id);
		len=strlen(id);
		sum=0;
		for(j=0; j<len; j++) {
			if(id[j]=='?') que=j;
			else sum+=(int)(id[j]-'0') * F[((len-j-1)%3)];
		}
	//	sum%=10; 
	//	sum=10-sum;
		for(j=0; j<10; j++)
		{
			int val=j*F[ (len-que-1)%3 ];
			if( (val + sum) % 10 == 0)
				break;
		}
		id[que]=(char)('0'+j);
		printf("Scenario #%d:\n%s\n\n", i, id);
	}//end for
	return 0;
}
