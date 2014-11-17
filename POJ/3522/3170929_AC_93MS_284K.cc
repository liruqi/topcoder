#include<algorithm>
#include<cstdio>

#define MV 101
#define ME 50000
int n,m;

struct edge{
    int u,v,w;
}ea[ME];
int father[MV];
int cnt[MV];

int root(int p){
    int r=p;
    while(father[r]>0) r=father[r];
    if(r!=p) father[p]=r;
    return r;
}

int slim(int start){
    memset(father,-1,sizeof(father));
    memset(cnt   ,-1,sizeof(cnt   ));
    int i;
    for(i=start;i<m;i++)
    {
        int u=ea[i].u;
        int v=ea[i].v;
        int ru=root(u);
        int rv=root(v);
        if(ru!=rv){
            father[rv]=ru;
            cnt[ru]+=cnt[rv];
        }
        if(cnt[ru]+n==0) return ea[i].w-ea[start].w;
    }
    return -1;
}

bool cmp(edge p,edge q){return p.w<q.w;}

int main()
{
    while(-1!=scanf("%d%d",&n,&m) && (n+m)){
        int i, j, res=-1;
        for(i=0;i<m;i++)
            scanf("%d%d%d",&ea[i].u, &ea[i].v, &ea[i].w);
        std::sort(ea,ea+m,cmp);
        for(i=0;i<m;){
            int sm = slim(i);
            if(sm==-1) break;
            if(res==-1 || res>sm) res=sm;
            for(j=i+1;j<m && ea[j].w==ea[i].w;j++);
            i=j;
        }
        printf("%d\n",res);
    }
}
