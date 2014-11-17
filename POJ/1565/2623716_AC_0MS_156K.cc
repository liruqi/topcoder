#include<stdio.h>
#include<string.h>
char num[50];
int main()
{
	int ans,i,len,p;
	while(1)
	{
		ans=0;
		p=0;
		gets(num);
		if(num[0]=='0')
			break;
		len=strlen(num);
		for(i=0;i<len;i++)
		{
			ans=ans*2+num[i]-'0';
			p+=num[i]-'0';
		}
		ans-=p/2;
		ans*=2;
		if(p%2==1)
			ans--;
		printf("%d\n",ans);
	}
	return 0;
}
