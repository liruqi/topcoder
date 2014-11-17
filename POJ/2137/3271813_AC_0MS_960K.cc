#include<stdio.h>
#include<string.h>
#include<math.h>

#define mx 1000

int N;
int xx[mx][40], yy[mx][40], nn[mx];
double dp[40][mx][40];

int main(){
    scanf("%d",&N);
    int i,j,k,s;
    double dx,dy,dt;
    for(i=0;i<N;i++) {
        scanf("%d",nn+i);
        for(j=0;j<nn[i];j++){
          scanf("%d",xx[i]+j);
          scanf("%d",yy[i]+j);
        }
    }
	for(j=0;j<nn[0];j++)
			for(s=0;s<nn[0];s++){
				dp[s][0][j]=0;
			}
	for(j=0;j<nn[1];j++)
			for(s=0;s<nn[0];s++){
				dx=xx[1][j]-xx[0][s];
				dy=yy[1][j]-yy[0][s];
				dt=sqrt(dx*dx+dy*dy);
				dp[s][1][j]=dt;
			}
    for(i=2;i<N;i++)
	{
		for(j=0;j<nn[i];j++)
			for(s=0;s<nn[0];s++)
				dp[s][i][j]=1e30;
		for(j=0;j<nn[i];j++){
			for(k=0;k<nn[i-1];k++){
				dx=xx[i][j]-xx[i-1][k];
				dy=yy[i][j]-yy[i-1][k];
				dt=sqrt(dx*dx+dy*dy);
				for(s=0;s<nn[0];s++) {
					dp[s][i][j]<?=(dt+dp[s][i-1][k]);
				}
			}
		}
	}
	
    double res=1e30;
    for(j=0;j<nn[N-1];j++)
		for(k=0;k<nn[0];k++)
		{
			dx=xx[N-1][j]-xx[0][k];
			dy=yy[N-1][j]-yy[0][k];
			dt=sqrt(dx*dx+dy*dy);
			res <?= dp[k][N-1][j]+dt;
		}
    printf("%d\n",int(res*100.0));
}
/*

3
3 0 1 0 0 0 -1
2 1 1 1 -1
3 2 1 2 0 2 -1

$1 = {{
        {0 <repeats 40 times>}, 
        {1, 1, 0 <repeats 38 times>}, 
        {2, 2.4142135623730949, 2, 0 <repeats 37 times>}, 
        {0 <repeats 40 times>} <repeats 997 times>
      }, 
      {
        {0 <repeats 40 times>}, 
        {1, 1, 0 <repeats 38 times>}, 
        {2, 2.4142135623730949, 2, 0 <repeats 37 times>}, 
        {0 <repeats 40 times>} <repeats 997 times>
      }, 
      {
        {0 <repeats 40 times>}, 
        {1, 1, 0 <repeats 38 times>}, 
        {2, 2.4142135623730949, 2, 0 <repeats 37 times>}, 
        {0 <repeats 40 times>} <repeats 997 times>
      },
      {
        {0 <repeats 40 times>} <repeats 1000 times>
      } <repeats 37 times>
     }
*/
