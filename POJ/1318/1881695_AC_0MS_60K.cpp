#include <stdio.h>
#include <string.h>

const char s[7]="******";
const char e[]="NOT A VALID WORD";
char ini[27]="aaaaaaaaaaaaaaaaaaaaaaaaaa";
char dic[100][7],dicT[100][27],wLen[100],a[7];
char t[27];
int i,j,k;
int main()
{			
	for(i=0;scanf("%s", dic[i])!=-1 && dic[i][0]!='X';i++)
    {
		strcpy(dicT[i],ini);
        wLen[i] = strlen(dic[i]);
		for(j=0; j<wLen[i]; j++)
		{
			k=dic[i][j] - 'a';
			dicT[i][k]++;
		}
    }				//build dictionary
	int dicLen=i;	//dictionary length
	int l[100],ll=0;
	bool flag;
	while(scanf("%s", a)!=-1 && a[0]!='X')
	{
		int sLen=strlen(a);
		strcpy(t,ini);
		for(i=0;i<sLen;i++)
		{
			j=a[i]-'a';
			t[j]++;
		}
		for(ll=0,flag=1,i=0;i<dicLen;i++)
		{	
			if(sLen==wLen[i])
			{
				if(strcmp(dicT[i],t)==0)
				{
					l[ll]=i;
					ll++;
					flag=0;
				}
			}
		}
		if(flag)
			puts(e);
		else
		{
			int tmp;
			for(i=1;i<ll;i++)
			{
				tmp=l[i];
				for(j=i-1;j>=0 && strcmp(dic[l[j]],dic[tmp])>0;j--)
					l[j+1]=l[j];
				l[j+1]=tmp;
			}
			for(i=0;i<ll;i++)
				puts(dic[l[i]]);
		}
		puts(s);
	}
	return 0;
}