#include <ctype.h>
#include <string.h>
#include <stdio.h>
char buf[40000];
int c2d(char c){
	if(isdigit(c))return c-'0';
	if(isupper(c))return c-'A'+10;
	if(islower(c))return c-'a'+36;
	return 0;
}

void solve(){
	int i,j,s=0,l=strlen(buf),m=0;
	for(i=0;i<l;i++) j=c2d(buf[i]),s+=j,m>?=j;
    i=m;
    i>?=1;
	for(;i<62;i++)if(s%i==0){printf("%d\n",i+1);return;}
	puts("such number is impossible!");
}

int main(){
	while(~scanf("%s",buf)) solve();
}
