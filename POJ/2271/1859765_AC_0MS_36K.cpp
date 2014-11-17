#include <iostream.h>
#include <string.h>
#include<stdio.h>
int i,j;

int main()
{
	char array[81];
	int col=0;
	while(cin>>array)
	{
		if(strcmp(array,"<br>")==0) 
		{
			cout<<endl;
			col=0;
			continue;
		}
		if(strcmp(array,"<hr>")==0) 
		{
			if(col) cout<<endl;
			for(i=0;i<80;i++)
				cout<<"-";
			cout<<endl;
			col=0;
			continue;
		}
	    else
		{
			if(col)
			{	
				cout<<" ";
				col ++;
			}
			j=strlen(array);
			if(col + j<=80 )
			{
				for(i=0;i<j;i++)
					cout<<array[i];
				col+=strlen(array);
			}
			else
			{
				if(col) cout<<endl;
				for(i=0;i<j;i++)
					cout<<array[i];
				col=j;
			}
		}
	}
	cout<<endl;
	return 0;
}
