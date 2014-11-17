#include <stdio.h>
#include <string.h>
const int maxn=200;

int n;
char x[maxn], y[maxn], z[maxn], r[maxn];

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		scanf("%s%s",x,y);
		printf("%d ", i);
		int xl=strlen(x), yl=strlen(y);
		int j, cy=0;
		if(xl<yl)
		{
			int d=yl-xl;
			strcpy(z+d, x);
			for(j=0; j<d; j++) 
				z[j]='0';
			strcpy(x, z);
		}
		else if(xl>yl)
		{
			int d=xl-yl;
			strcpy(z+d, y);
			for(j=0; j<d; j++) 
				z[j]='0';
			strcpy(y, z);
		}
//		puts(x);
//		puts(y);
		j=strlen(x);
		r[j]='\0';
		for(j--; j>=0; j--)
		{
			int s=x[j]-'0' + y[j]-'0' ;
			s+=cy;
			r[j]='0' + s%2;
			cy=s/2;
		}
		if(cy)
		{	
			putchar('1');
			puts(r);
		}
		else
		{
			j=0;
			while(r[j]=='0')
				j++;
			if(r[j]=='\0')
				puts("0");
			else
				puts(r+j);
		}
	}
	return 0;
}
