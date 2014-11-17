#include <stdio.h> 
#include <string.h> 

bool dif[3000]; 

char *out[2]={"Jolly","Not jolly"}; 
int absv(int x) 
{ 
	return x<0?(-1)*x:x; 
} 
int main() 
{ 
	int n, i, a, b, res; 
	while(scanf("%d", &n)!=EOF) 
	{	
		res=1; 
		memset(dif, 0, sizeof(dif)); 
		scanf("%d", &a); 
		for(i=1; i<n; i++) 
		{ 
			scanf("%d", &b); 
			if(absv(a-b)>=3000)
				res=0;
			else
				dif[absv(a-b)]=1; 
			a=b; 
		} 
		
		for(i=1; i<n && res; i++) 
			if(!dif[i]) 
				res=0; 
		printf("%s\n", res?out[0]:out[1]); 
	}
return 0;
} 
