#include<stdio.h>
#include<string.h>
#define maxn 100
char pt[maxn], ct[maxn];
int pc[maxn], cc[maxn];


int t2c(char c){
	if(c=='_')return 0;
	if(c=='.')return 27;
	return c-'a'+1;
}
char c2t(int n){
	if(n==0)return '_';
	if(n==27)return '.';
	return 'a'+n-1;
}

int main()
{
	int i;
	int k,n;
	while(EOF!=scanf("%d",&k) && k>0)
	{
		scanf("%s",ct);
		n=strlen(ct);
		memset(pt,0,maxn);
		for(i=0;i<n;i++)
			cc[i]=t2c(ct[i]);
		for(i=0;i<n;i++)
			pc[(k*i)%n]=(cc[i]+i)%28;
		for(i=0;i<n;i++)
			pt[i]=c2t(pc[i]);
		puts(pt);
	}
	
	return 0;
}

