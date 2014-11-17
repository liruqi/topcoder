#include <stdio.h>
#include <string.h>
#include <math.h>
char sf[46], ss[46];
int c1[27], c2[27];
int main()
{
	int N, i, t, n1, n2, c;
	scanf("%d", &N); getchar();
	for(c=1; c<=N; c++)
	{
		int cnt=0;gets(sf); 
		gets(ss);
		n1=strlen(sf); 
		n2=strlen(ss);
//		printf("strlen: %d %d \n", n1, n2);
		memset(c1, 0, 4*27); 
		memset(c2, 0, 4*27);
		
		for(i=0; i<n1; i++) 
		{
			t = sf[i]-'a' ;
			c1[t]++;
		}
		for(i=0; i<n2; i++) 
		{
			t = ss[i]-'a' ;
			c2[t]++;
		}
		
		for(i=0; i<26; i++)
		{
//			printf("%c: %d %d\n",'a'+i, c1[i], c2[i]);
			cnt += abs(c1[i]-c2[i]);
		}
		printf("Case #%d:  %d\n",c, cnt);
	}
	return 0;
}
