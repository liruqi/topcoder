#include<stdio.h>
#include<algorithm>

#define maxn 300
int ps[maxn],ns[maxn],pt,nt;
int zero;
int N,K;
int pc,nc,zc;

int rcp(int p,int q){return p>q;}

int getsgn(){
	int pon=0;
	if(K<pt+nt){
		if(pt) pon = 1;
		else if(K%2) pon = -1;
		else pon = 1;
	}
	else if(K==pt+nt){
		if(nt%2) pon=-1;
		else pon=1;
	}
	if(zero)
	{
		if(pon>0)return 1;
		return 0;
	}
	
	return pon;
}

void pos(){
	int i;
	std::sort(ps,ps+pt,rcp);
	std::sort(ns,ns+nt);
	for(i=K;i;i--) {
		if(pc==pt)nc++;
		else if(nc==nt)pc++;
		else (ps[pc]>-ns[nc])?pc++:nc++;
	}
	if(nc%2){
		int add;
		if(nc==nt||pc==0)add=1;
		else if(pc==pt||nc==0)add=-1;
		else add=(ps[pc]*ps[pc-1]>ns[nc]*ns[nc-1])?1:-1;
		add==1?(nc--,pc++):(nc++,pc--);
	}
}

void neg(){
	int i;
	std::sort(ps,ps+pt);
	std::sort(ns,ns+nt,rcp);
	for(i=K;i;i--) {
		if(pc==pt)nc++;
		else if(nc==nt)pc++;
		else (ps[pc]>-ns[nc])?pc++:nc++;
	}
}

void zer(){
	if(K<=zero) zc=K;
	else {
		int rem=K-zero;
		zc=zero;
		if(rem<=pt)pc=rem;
		else {
			pc=pt;
			nc=rem-pc;
		}
	}
}

void prt(){
	int buf[maxn],top=0,i;
	for(i=0;i<nc;i++)buf[top++]=ns[i];
	for(i=0;i<zc;i++)buf[top++]=0;
	for(i=0;i<pc;i++)buf[top++]=ps[i];
	std::sort(buf,buf+top,rcp);
	
	for(i=0;i<top;i++)
		printf("%d%c", buf[i], i+1==top?'\n':' ');
}

int main(){
	int i,t;
	scanf("%d%d",&N,&K);
	for(i=N;i;i--){
		scanf("%d",&t);
		if(t>0)ps[pt++]=t;
		else if(t<0)ns[nt++]=t;
		else zero++;
	}
	int sgn = getsgn();

	
	if(sgn>0) pos();
	else if(sgn<0) neg();
	else zer();
	
	prt();
}
