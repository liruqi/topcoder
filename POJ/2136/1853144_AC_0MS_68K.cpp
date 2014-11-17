#include<iostream>
//#include <stdio.h>

using namespace std;
int main()
{
	char a[4][80];
	int s[27],i,j,max=0,k=0;
	bool f;
//	FILE *fp=fopen("d.txt","w");
	cin.getline(a[0],80);
	cin.getline(a[1],80);
	cin.getline(a[2],80);
	cin.getline(a[3],80);
	
	for(i=0;i<27;i++)
		s[i]=0;
	for(i=0;i<4;i++)
		for(j=0;j<80 && a[i][j];j++)
		{
			if(a[i][j]>='A' && a[i][j]<='Z')
			{
				k=a[i][j]-'@';
				s[k]++;
			}
		}
	for(i=1;i<27;i++)
	{
		if(s[i]>max)
			max=s[i];
	}
	for(j=max;j>0;j--)
	{
		for(i=1;i<27;i++)
		{
			if(s[i] >= j)
			{
				cout<<"*";
//				fprintf(fp,"*");
				if(i==26)
					break;
				for(f=0,k=i+1;k<27;k++)
				{
					if(s[k]-j>=0)
						f=1;
				}
				if(!f)
					break;
			}
			else 
			{
				cout<<" ";
//				fprintf(fp," ");
			}
			cout<<" ";
//			fprintf(fp," ");
		}
		cout<<endl;
//		fprintf(fp,"\n");
	}
	cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
//	fprintf(fp,"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	return 0;
}
