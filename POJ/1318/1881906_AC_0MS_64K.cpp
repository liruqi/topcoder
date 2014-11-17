#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char s[7]="******";
const char e[]="NOT A VALID WORD";
char ini[27]="aaaaaaaaaaaaaaaaaaaaaaaaaa";

char dic[100][7],dicT[100][27],wLen[100],a[7];
char t[27];
int i,j,k;

int cmp(const void*a, const void*b)
{
	return strcmp(dic[*(int *)a], dic[*(int *)b]);
}

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
			qsort(l,ll,sizeof(int),cmp);
			for(i=0;i<ll;i++)
				puts(dic[l[i]]);
		}
		puts(s);
	}
	return 0;
}