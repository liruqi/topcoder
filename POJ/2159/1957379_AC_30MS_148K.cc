#include <iostream>
#include <string.h>
using namespace std;

char i1[110], i2[110];
char t1[30], t2[30];
int cmp(const void *a, const void *b)
{
	int k = (int)(*(const char *)a - *(const char *)b);
	return k;
}

int main()
{
	int i,j;
	memset(t1,'a',26);
	memset(t2,'a',26);
	
	cin>>i1>>i2;
	for(i=0; i1[i]!='\0'; i++)
	{	
		j = (int)(i1[i] - 'A');
		t1[j]++;
		
		j = (int)(i2[i] - 'A');
		t2[j]++;
	}

	qsort(t1,26,1,cmp);
	qsort(t2,26,1,cmp);
	
	if(strcmp(t1,t2)) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	
	return 0;
}

