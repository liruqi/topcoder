#include <stdio.h>
#include <string.h>

char buf[1100000];
int X;

int seg(int l){
	int i,j;
	for(i=0;i<l;i++)
		for(j=i+l; j<X; j+=l)
			if(buf[i]!=buf[j])
				return 0;
	return 1;
}

int sol(){
	int i;
	X=strlen(buf);
	for(i=1;i<=X;i++)if(X%i==0)
		if(seg(i)){
			printf("%d\n",X/i);
			return 0;
		}
}

int main()
{
	while(gets(buf) && buf[0]!='.') 
		sol();
	return 0;
}
