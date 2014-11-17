#include <iostream>
using namespace std;

char str1[10], str2[10], w[5];
int flg[12];
bool exi[12];
int t,i,j,k;
int main()
{
	cin>>t;
	for(i=1;i<=t;i++)
	{
		for(j=0;j<12;j++) flg[j] = 100;
		for(j=0;j<3;j++)
		{
			cin>>str1>>str2>>w;
			switch(w[0])
			{
				case 'e':
					for(k=0; str1[k] != '\0'; k++) flg[str1[k]-'A']=0;
					for(k=0; str2[k] != '\0'; k++) flg[str2[k]-'A']=0;
					break;
					
				case 'u':
					for(k=0; k < 12; k++) exi[k]=1; 
					for(k=0; str1[k] != '\0'; k++) 
					{
						int tmp=str1[k]-'A';
						exi[tmp]=0;
						if(flg[tmp]) flg[tmp]=(flg[tmp]==-1) ? 0 : 1;
					}
					for(k=0; str2[k] != '\0'; k++) 
					{
						int tmp=str2[k]-'A';
						exi[tmp]=0;
						if(flg[tmp]) flg[tmp]=(flg[tmp]==1) ? 0 : -1;
					}
					for(k=0; k<12; k++) if(exi[k])
						flg[k]=0;
					break;
					
				case 'd':
					for(k=0; k < 12; k++) exi[k]=1; 
					for(k=0; str1[k] != '\0'; k++) 
					{
						int tmp=str1[k]-'A';
						exi[tmp]=0;
						if(flg[tmp]) flg[tmp]=(flg[tmp]==1) ? 0 : -1;
					}
					for(k=0; str2[k] != '\0'; k++) 
					{
						int tmp=str2[k]-'A';
						exi[tmp]=0;
						if(flg[tmp]) flg[tmp]=(flg[tmp]==-1) ? 0 : 1;
					}
					for(k=0; k<12; k++) if(exi[k])
						flg[k]=0;
					break;
			}
		}
//		for(k=0;k<12;k++) cout<<flg[k]<<" ";
	
		for(k=0;k<12;k++) if(flg[k] && flg[k]!=100)
		{
			char tmp='A';
			tmp += k;
			cout<<tmp<<" is the counterfeit coin and it is ";
			if(flg[k]==-1)
				cout<<"light."<<endl;
			else
				cout<<"heavy."<<endl;
			break;
		}
	}
	return 0;
}
