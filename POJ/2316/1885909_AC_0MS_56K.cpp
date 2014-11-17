#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char num[15];
char total[15];
int main()
{
	int i,len,temp;
        memset(total,0,sizeof(total));
	memset(num,0,sizeof(num));
    	gets(total);    
    	while(gets(num)!=0)
	{
		len=strlen(num);
		for(i=0;i<len;i++)
		{
			total[i]=(total[i]+num[i]-'0'-'0')%10+'0';
		}

	} 
	 	printf("%s",total);
    //getchar();
	return 0;
}

