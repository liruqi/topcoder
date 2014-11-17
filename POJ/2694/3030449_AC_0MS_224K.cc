#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

int T;
char hand[5][5];

int cnt[20];
int suit[5];
int c2i[128];
int card[6];
int top;
bool cmp(int p,int q){return p>q;}
void init(){
	int i;
	memset(cnt,0,sizeof(cnt));
	memset(suit,0,sizeof(suit));
	for(i=0;i<5;i++){
		if(isdigit(hand[i][1]))cnt[hand[i][1]-'0']++;
		else cnt[c2i[hand[i][1]]]++;
		suit[c2i[hand[i][0]]]++;
	}
	top=0;
	for(i=1;i<=13;i++)if(cnt[i])card[top++]=cnt[i];
	sort(card,card+top,cmp);
	sort(suit+1,suit+5,cmp);
}

int r2(){
	return card[0]==4&&card[1]==1;
}
int r3(){
	return card[0]==3&&card[1]==2;
}
int r4(){
	return suit[1]==5;
}
int r5(){
	int i,len;
	for(i=1;!cnt[i];i++);
	for(len=0;i<=13&&cnt[i];i++)len++;
	return (len==5||(cnt[1]&&cnt[10]&&cnt[11]&&cnt[12]&&cnt[13]));
}
int r6(){
	return card[0]==3&&card[1]==1&&card[2]==1;
}
int r7(){
	return card[0]==2&&card[1]==2&&card[2]==1;
}
int r8(){
	return card[0]==2&&card[1]==1&&card[2]==1&&card[3]==1;
}

int main(){
int k;
c2i['A']=1;
c2i['X']=10;
c2i['J']=11;
c2i['Q']=12;
c2i['K']=13;
c2i['C']=1;
c2i['H']=2;
c2i['S']=3;
c2i['D']=4;
scanf("%d",&T);
while(T--){
for(k=0;k<5;k++)scanf("%s",hand[k]);
init();
if(r4()&&r5())puts("1000");
else if(r2())puts("750");
else if(r3())puts("500");
else if(r4())puts("350");
else if(r5())puts("250");
else if(r6())puts("200");
else if(r7())puts("100");
else if(r8())puts("50");
else puts("0");
}
}