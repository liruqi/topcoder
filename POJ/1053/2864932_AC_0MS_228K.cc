#include <stdio.h>
#include <set>
using namespace std;

char card[13][6];
int cnt;

int judge(int x,int y,int z){
	int i;for(i=0;i<4;i++){
		set<char> sc; sc.insert(card[x][i]);sc.insert(card[y][i]);sc.insert(card[z][i]);
		if(sc.size()==2)return 0;
	}return 1;
}

int main(){
	int i,j,k;
	while(gets(card[1])){if(card[1][0]==10)break;
		cnt=0; for(i=2;i<13;i++)gets(card[i]); gets(card[0]);
		printf("CARDS: ");for(i=1;i<13;i++)printf(" %s",card[i]); puts("");
		for(i=1;i<=10;i++)for(j=i+1;j<=11;j++)for(k=j+1;k<=12;k++)
		if(judge(i,j,k))printf(cnt?"        ":"SETS:   "),printf("%d.  %s %s %s\n",++cnt,card[i],card[j],card[k]);
		if(!cnt)puts("SETS:   *** None Found ***");puts("");
	}
}