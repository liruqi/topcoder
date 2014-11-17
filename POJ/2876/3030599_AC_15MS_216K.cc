#include <stdio.h>
void prt(int pl,int v){
	if(pl){
		if(v)prt(pl-1,1),prt(pl-1,0),prt(pl-1,1);
		else prt(pl-1,0),prt(pl-1,0),prt(pl-1,0);
	}
	else putchar(v?'-':' ');
}
int main(){
	int N;
	while(~scanf("%d",&N))
	prt(N,1),puts("");
}
