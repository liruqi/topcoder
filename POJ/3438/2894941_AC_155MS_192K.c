#include <stdio.h>
#include <string.h>

char buf[1100];

void solve(){
int i,j,l=strlen(buf);
for(i=0;i<l;i=j){
	int cnt=1;
	for(j=i+1; buf[j]==buf[i]; j++)cnt++;
	printf("%d",cnt);putchar(buf[i]);
}
puts("");
}

int main(){
int ks;
scanf("%d\n",&ks);
while(ks--){
gets(buf);
solve();
}
return 0;
}
