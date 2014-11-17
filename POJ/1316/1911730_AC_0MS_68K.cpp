#include <stdio.h>
#define MS 10000
//			   1   3   5   7   9  
bool sn[MS]={0,1,0,1,0,1,0,1,0,1,0};
int a[4];
inline int dig(int n)				//digitadition
{
	int i;
	a[0]=n%10;
	a[1]=(n%100)/10;
	a[2]=(n%1000)/100;
	a[3]=n/1000;
	for(i=0; i<4; i++) n+=a[i];
	return n;
}

int main()
{
	int i,j;
	for(i=11; i<MS; i++) sn[i]=1;
	for(i=5; i<MS; i++)
	{
		j=dig(i);
		if(j<MS) sn[j]=0;
	}
	for(i=0; i<MS; i++)
		if(sn[i] == true)
			printf("%d\n",i);
	return 0;
}
