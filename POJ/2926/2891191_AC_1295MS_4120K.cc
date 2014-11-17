#include<stdio.h>

double dat[100001][5];
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf%lf%lf%lf%lf",&dat[i][0],&dat[i][1],&dat[i][2],&dat[i][3],&dat[i][4]);
	double res = -1e10;
	for(i=0;i<32;i++){
		double mns=1e200;
		double mxs=-1e200;
		for(k=1;k<=n;k++){
			double cur=0;
			
			for(j=0;j<5;j++)
				if( i&(1<<j) ) cur-=dat[k][j];
				else cur+=dat[k][j];

			mns<?=cur;
			mxs>?=cur;
		}
		res>?=(mxs-mns);
	}

	printf("%.2f\n",res);

	return 0;
} 
