#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define mx 100001
int N,M,lmi,i,j,k,t,r;
struct rec{
	int scr;
	char stn[31];
};
rec cnt[mx], rkd[mx];
int cmp(const void *p,const void *q){
return strcmp( ((rec*)p)->stn, ((rec*)q)->stn );
}
int main(){
scanf("%d\n",&N);
for(i=0;i<N;i++){gets(cnt[i].stn);}
qsort(cnt,N,sizeof(rec),cmp);
for(i=0;i<N;i++)if(!strcmp(cnt[i].stn,"Li Ming"))lmi=i;
scanf("%d",&M);
for(j=0;j<M;j++){
	for(i=0;i<N;i++){
	scanf("%d ",&rkd[i].scr);
	gets(rkd[i].stn);
	}
	qsort(rkd,N,sizeof(rec),cmp);
	for(i=0;i<N;i++){
	cnt[i].scr+=rkd[i].scr;
	}
	for(r=1,i=0;i<N;i++)if(cnt[i].scr>cnt[lmi].scr)r++;
	printf("%d\n",r);
}
}
