#include<stdio.h>
#include<string.h>
#define maxn 30
typedef struct _pit{
	int x,y;
}pit;
typedef struct _rec{
	pit ul, lr;
}rec;

rec Rt[maxn];//A,B,C...
pit Pt[maxn];//1,2,3...
bool adj[maxn][maxn];
bool unk[maxn],vst[maxn];
int N;

bool dfs(int p,int mah[]){
	int i,t;
	for(i=1;i<=N;i++)if(adj[p][i] && !vst[i]){
		vst[i]=1;
		if(mah[i]<0 || dfs(mah[i], mah)){
			mah[i]=p;
			return true;
		}
	}
	return false;
}


int bgmatch(int mah[]){
	int cnt=0,i;
	for(i=1;i<=N;i++){
		memset(vst, 0, sizeof(vst));
		if(dfs(i, mah))
			cnt++;
	}
	return cnt;
}

bool inRec(pit p, rec r){
	return p.x>r.ul.x && p.x<r.lr.x && p.y>r.ul.y && p.y<r.lr.y;
}

void build_bi_graph(){
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			adj[i][j]=inRec(Pt[i],Rt[j]);
			/*
	for(i=1;i<=N;i++)
		for(puts(""),j=1;j<=N;j++)
			printf("%d ",adj[i][j]);
			*/
}

int main()
{
	int i,j,ks=1;
	int match[30], mtest[30];
	while(scanf("%d",&N), N){
		memset(adj,   0,  sizeof(adj)  );
		for(i=1;i<=N;i++) 
			scanf("%d%d%d%d",&Rt[i].ul.x, &Rt[i].lr.x, &Rt[i].ul.y, &Rt[i].lr.y);
		for(i=1;i<=N;i++) 
			scanf("%d%d",&Pt[i].x, &Pt[i].y);
		build_bi_graph();
		
		memset(match, -1, sizeof(match));
		memset(unk,   0,  sizeof(unk)  );
		int mme = bgmatch(match);
		int cum = 0;//count unique match
		for(i=1; i<=N; i++) if(match[i]>0){
			adj[match[i]][i]=0;
			memset(mtest, -1, sizeof(mtest));
			int cme = bgmatch(mtest);
			if(cme < mme){
				unk[i]=1;
				cum++;
			}
			adj[match[i]][i]=1;
		}
		printf("Heap %d\n",ks++);
		if(cum){
			for(i=1,j=1;i<=N;i++)
				if(match[i]>0 && unk[i])
					printf("(%c,%d)%c",'A'+i-1,match[i],j==cum?'\n':' '), j++;
		}
		else puts("none");
		puts("");
	}
}

/*

2
0 4 0 4
1 5 1 5
2 2
3 3

2
0 4 0 4
1 5 1 5
1 2
3 3

2
0 4 0 4
2 5 2 5
1 2
3 3
*/