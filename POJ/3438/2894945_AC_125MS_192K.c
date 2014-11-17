#include <stdio.h>
#include <string.h>

char buf[1100];

void solve(){
int i,j,l=strlen(buf),c;
for(i=0;i<l;i=j){
for(c=1,j=i+1; buf[j]==buf[i]; j++)c++;
printf("%d",c);putchar(buf[i]);
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
