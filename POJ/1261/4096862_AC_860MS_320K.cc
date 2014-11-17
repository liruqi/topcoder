
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define ni(x) (scanf("%d", &x))
#define ns(x) (scanf("%s",  x))
#define si(x) (printf("%s: %d\n", #x, x))


int	Z,N,hl,dangle,path;
char H[200 + 40], str[200 + 40];;

int LT[20],RT[20];

struct node{
	struct node* next[10];
	int leaf;
	void clear(){
		memset(next,0,sizeof(next));
		leaf=0;
	}
};
node na[200*20];
node* root = na;
int top;

node* new_node()
{
	(na+top)->clear();
	return na+(top++);
}
void del_node(node* p, int hp)
{
	if(!p->next[ H[hp] ]) return;
	del_node(p->next[ H[hp] ], hp+1);
	top--;
	p->next[ H[hp] ]=0;
}


int match(int zp)
{
	int bg = LT[zp];
	int sz = RT[zp]-LT[zp]-1;

	int cnt=0;
	for(int pos=bg+sz; pos+sz<=hl; )
	{
		int add;
		for(add=0;add<sz && H[pos+add]==H[bg+add];add++);
		if(add == sz)
		{
			pos += sz;
			cnt++;
		}
		else {
			pos++;
		}
		//si(pos);
		if(cnt>=N-1) break;
	}
	return cnt;
}

int dfs(int zp,int hp)
{
	//si(hp);
    if(dangle > (Z-zp)) return 0;
	if(path > (hl-hp)) return 0;
	if(zp == Z)
	{
		return hp==hl && dangle==0;
	}
	// 0 <= zp < Z
	LT[zp] = hp;
	node* pt = root;
	int bs;
	for(bs=hp; bs<hl && pt->next[ H[bs] ]; bs++)
		 pt = pt->next[ H[bs] ];

	if(bs == hl) return 0;
	if(pt->leaf) return 0;

	int np;
	node* it = pt;
	int dbak = dangle;
	int pbak = path;
	for(np=bs; np<hl; np++)
	{
		it->next[ H[np] ] = new_node();
		it = it->next[ H[np] ];
		it->leaf = 1;
		dangle -= 1;
		path -= (np-hp+1);
		RT[zp] = np+1;
		if(dfs(zp+1, np+1))
			return 1;
		it->leaf = 0;
		dangle += N;
		path += N*(np-hp+2);
		if(np>bs && match(zp) < N-1)
			break;
	}
	del_node(pt, bs);
	path = pbak;
	dangle = dbak;
	return 0;
}

int main()
{
	int ks;
	ni(ks);
	while(ks--)
	{
		top = 1;
		root->clear();
		ni(Z);
		ni(N);
		ns(str);
		hl = strlen(str);
		for(int i=hl-1;i>=0;i--) H[i]=str[i]-'0';
		
		dangle = N;
		path = N;
		if(!dfs(0,0))
		{
			puts("err");
			return 0;
		}
		for(int i=0;i<Z;i++)
		{
			printf("%d->", i);
			for(int p=LT[i];p<RT[i];p++)
				printf("%d", H[p]);
			puts("");
		}
	}
}
