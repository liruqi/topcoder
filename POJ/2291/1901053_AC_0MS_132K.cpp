#include <iostream>
#define MAX 1010
using namespace std;
int tow[MAX],t,w,mi,n,i;

int cmp(const void *x, const void *y)
{
	return *(int *)y - *(int *)x;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>tow[i];
		
		qsort(tow,n,4,cmp);
		
		for(w=i=0;i<n ; i++)
		{
			if(tow[i]*(i+1) > w)
			{
				mi = i;
				w=tow[i]*(i+1);
			}
		}
		cout<<w<<endl;
	}
	return 0;
}