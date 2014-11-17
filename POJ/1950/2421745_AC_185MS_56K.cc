#include <stdio.h>
int N,cnt;

char m[20];

int bb(int ln, int n){
    if(n>9) return ln*100+n;
    return ln*10+n;
}

void printans()
{
    printf("1");
    for(int i=2;i<=N;i++)
        printf(" %c %d",m[i],i);
        puts("");
}

void dfs(int p, int s, int ln, char lo){
    if(p>N) {
        if(s==0) 
        {
            cnt++;
            if(cnt<=20) 
                printans();
        }
        return ;
    } 
    m[p]='+';
    dfs(p+1,s+p,p,'+');
    m[p]='-';
    dfs(p+1,s-p,p,'-');
    m[p]='.';
    int sign=lo=='+'?1:-1;
    int tn=bb(ln,p);
    dfs(p+1,s+sign*(tn-ln),tn,lo); 
}

int main()
{
    scanf("%d",&N);
    dfs(2,1,1,'+');
    printf("%d\n",cnt);
    scanf("%d",&N);
}
