#include<stdio.h>
#include<string.h>

int c[4][4],f[4][4];
bool b[4];
int ans;

void init()
{
    int a,b;
    scanf("%d%d",&a,&b);
    c[0][1]=a;c[1][3]=a;
    c[0][2]=b;c[2][3]=b;
}

bool find(int x)
{
    if(x==3)return true;
    for(int i=0;i<4;i++)
    {
        if(f[x][i]<c[x][i]&&!b[i])
        {
            b[i]=true;
            if(find(i))
            {
                f[x][i]++;f[i][x]--;
                return true;
            }
        }
    }
    return false;
}

void process()
{
    ans=0;
    memset(b,false,sizeof(b));
    b[0]=true;
    while(find(0))
    {
        memset(b,false,sizeof(b));
        b[0]=true;
        ans++;
    }
}

int main()
{
    init();
    process();
    printf("%d\n",ans);
}
