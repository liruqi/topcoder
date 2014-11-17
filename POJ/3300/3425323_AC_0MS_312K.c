#include<stdlib.h>

int i,j,f,r,top;
double ft[20],rt[20],dat[300];
int cmp(const void *p,const void *q){return *(double*)p-*(double*)q<0?-1:1;}
int main(){
	while(1)
	{
		scanf("%d",&f);
		if(!f) break;
		scanf("%d",&r);
		
		for(i=0;i<f;i++)
			scanf("%lf",ft+i);
		for(i=0;i<r;i++)
			scanf("%lf",rt+i);
		top=0;
		for(i=0;i<f;i++)for(j=0;j<r;j++)dat[top++]=rt[j]/ft[i];
		qsort(dat,top,sizeof(double),cmp);
		double can,ret=0;
		for(i=1;i<top;i++){
			can=dat[i]/dat[i-1];
			if(can>ret)
				ret=can;
		}
		printf("%.2lf\n",ret);
	}
}
