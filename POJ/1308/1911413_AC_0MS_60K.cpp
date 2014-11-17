#include <stdio.h>
#include <string.h>
#define MS 80
int node[MS];
bool bpt[MS];
int i,root,d;

int get_root(int n)
{
    if(d-- <= 0) return 0;
    if(node[n] == 0) return n;
    return get_root(node[n]);
}

int main()
{
    int x,y,cas = 1;
    scanf("%d%d",&x,&y);
    while(x != -1 && y!=-1)
    {
        bool tree = 1;
        memset(node, 0, sizeof(node));   //sizeof(node) = 4* MS
        memset(bpt, 0, sizeof(bpt));     
        root=x;
        
        while(x && y)
        {
            if(bpt[y]) tree = 0;    
            node[y] = x;				//record the position be pointed
            bpt[y]=1;
            if(y==root) root = x;       //adjust root
            scanf("%d%d",&x,&y);
        }
        if(tree) for(i=0; i<MS; i++)
        {
            
            if(node[i])
				if(d=MS,get_root(i)!=root)
				{
					tree=0; break;
				}
        }
        printf("Case %d ",cas++);
        if(tree) puts("is a tree.");
        else puts("is not a tree.");
        scanf("%d%d",&x,&y);
    }
    return 0;
}
