#include <stdio.h>
#define MaxN 30

int base[MaxN], cnt[MaxN], top;
int a, aa;
long long  res,tmp;

void dfs(int k, int div, int mul, int key){
    int i, euler;
    if (k==top){
        euler = key/div*mul;
        tmp=aa/key*euler;
		res += tmp;
    }
    else{
        dfs(k+1, div, mul, key);
        for (i=1; i<=cnt[k]; i++){
            key*=base[k];
            dfs(k+1,div*base[k], mul*(base[k]-1), key);
        }
    }
}

void solve(){
    int i;
    aa = a;
    for (i=2, top=0; i<=a/i; i++){
        if (a%i) continue;
        base[top] = i;
        cnt[top] = 0;
        while (a%i==0){
            a /= i;
            cnt[top]++;
        }
        top++;
    }
    if (a!=1){
        base[top] = a;
        cnt[top] = 1;
        top++;
    }
    res = 0;
    dfs(0, 1, 1, 1);
    printf("%I64d\n", res);
}

int main(){
    while (EOF != scanf("%d", &a) && a)
        solve();
    return 0;
}