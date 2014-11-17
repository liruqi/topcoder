#include <stdio.h>
#include <string.h>
#define maxn 100
#define inf 0x0f0f0f0f
int T, K, L, freq[maxn];
char key[maxn], let[maxn];
int sg[maxn][maxn];//single key
int dp[maxn][maxn];

void solve(){
int s,e,k;
memset(sg,0,sizeof(sg));
memset(dp,0,sizeof(dp));
for(s=1;s<=L;s++)scanf("%d",freq+s);
for(s=1;s<=L;s++)for(e=s;e<=L;e++)sg[s][e]=sg[s][e-1]+(e-s+1)*freq[e];
for(e=1;e<=L;e++)dp[1][e]=sg[1][e];
for(k=2;k<=K;k++)for(e=1;e<=L;e++){
dp[k][e]=inf;
for(s=1;s<=e+1;s++)dp[k][e]<?=dp[k-1][s-1]+sg[s][e];
}
}

void printk(int k,int s,int e){
printf("%c: ",key[k]);
int i;
for(i=s;i<=e;i++)putchar(let[i]);putchar(10);
}

void output(int k,int e){
if(k==0) return;
int s;
for(s=1;s<=e+1;s++)if(dp[k][e]==dp[k-1][s-1]+sg[s][e]){
output(k-1,s-1);
printk(k,s,e);
return;
}
}

int main(){
int ks=1;
scanf("%d",&T);
for(;ks<=T&&-1!=scanf("%d%d",&K,&L);ks++){
printf("Keypad #%d:\n",ks);
scanf("%s%s",key+1,let+1);
solve();
output(K,L);
puts("");
}
}