#include<stdio.h>
#include<string.h>
char buf[40][200];
char dig[40];
int s;
int up[]={1,0,1,1,0,1,1,1,1,1};
int md[]={0,0,1,1,1,1,1,0,1,1};
int lw[]={1,0,1,1,0,1,1,0,1,1};
int ul[]={1,0,0,0,1,1,1,0,1,1};
int ur[]={1,1,1,1,1,0,0,1,1,1};
int ll[]={1,0,1,0,0,0,1,0,1,0};
int lr[]={1,1,0,1,1,1,1,1,1,1};
int i,j,len;
void
colset(int rs,int re,int co){
for(j=rs;j<=re;j++)buf[j][co]='|';
}
void
write(){
len=strlen(dig);
for(i=0;i<len;i++)if(up[dig[i]-'0'])memset(buf[0]+(s+3)*i+1,'-',s);
for(i=0;i<len;i++)if(md[dig[i]-'0'])memset(buf[1+s]+(s+3)*i+1,'-',s);
for(i=0;i<len;i++)if(lw[dig[i]-'0'])memset(buf[2+2*s]+(s+3)*i+1,'-',s);
for(i=0;i<len;i++)if(ul[dig[i]-'0'])colset(1,s,(s+3)*i);
for(i=0;i<len;i++)if(ur[dig[i]-'0'])colset(1,s,(s+3)*i+s+1);
for(i=0;i<len;i++)if(ll[dig[i]-'0'])colset(s+2,2*s+1,(s+3)*i);
for(i=0;i<len;i++)if(lr[dig[i]-'0'])colset(s+2,2*s+1,(s+3)*i+s+1);
}
void
output(){
for(i=0;i<2*s+3;i++){
for(j=0;j<(s+3)*len;j++)putchar(buf[i][j]);puts("");
}
puts("");
}
int
main(){
while(scanf("%d%s",&s,dig), s)memset(buf,' ',sizeof(buf)),write(),output();
}