#include <stdio.h>
#include <string.h>
#define MS 100
int node[MS];
int rmt[MS];
bool bpt[MS];
int i,root,d;

int get_root(int n)
{
    if(d-- <= 0) return 0;
    if(node[n] == 0) return n;
    if(!rmt[n]) rmt[n] = get_root(node[n]);
    return rmt[n];
}

int main()
{
    int x,y,cas = 1;
    scanf("%d%d",&x,&y);
    while(x != -1 && y!=-1)
    {
        bool tree = 1;
		for(i=0;i<MS;i++)
		{
			node[i]=0;
			bpt[i]=0;
			rmt[i]=0;
		}
        root=x;
        
        while(x && y)
        {
            if(bpt[y])                  //asure only one edge pointing to it. 
            {
                tree = 0;
            }
            node[y] = x;				//record the position be pointed
            bpt[y]=1;
            if(y==root) root = x;       //adjust root
            scanf("%d%d",&x,&y);
        }
        if(tree) for(i=0; i<MS; i++)
        {
            d=MS;
            if(node[i])
				if(get_root(i)!=root)
				{
					tree=0; break;
				}
        }
        printf("Case %d ",cas++);
        if(tree)
            puts("is a tree.");
        else
            puts("is not a tree.");
        scanf("%d%d",&x,&y);
    }
    return 0;
}
