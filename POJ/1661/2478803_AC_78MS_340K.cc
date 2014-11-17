#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxh 20001
#define maxn 1001
typedef struct platform{
    int x[2], h;
}pf;
pf P[maxn];

bool cmp(pf a, pf b){
    return a.h<b.h;
}

int T[maxn][2];
int main()
{
	int N,X,Y,MAX;
	int t;
	
	cin>>t;
	while(t--){
		int x1, x2, y;
		int i,j,k,d;
		memset(T, 0x7f, maxn<<3);
        cin>>N>>X>>Y>>MAX;
		for(i=1; i<=N; i++){
			cin>>P[i].x[0]>>P[i].x[1]>>P[i].h;
		}

		sort(P+1,P+N+1,cmp);

        for(i=1;i<=N && P[i].h<=Y;i++){
    		for(j=0;j<2;j++){
                for(k=i-1;k>0 && P[i].h-P[k].h<=MAX;k--){
                    // if able to launch
                    if((P[k].x[0]-P[i].x[j])<=0 && (P[k].x[1]-P[i].x[j])>=0)
                    {
                        int t=min(T[k][0]+fabs(P[k].x[0]-P[i].x[j]),
                                  T[k][1]+fabs(P[k].x[1]-P[i].x[j]));
                        if(T[i][j]>t)
                            T[i][j]=t;
                        break;
                    }
                    
                }
                if(k==0 && P[i].h<=MAX) {
                     T[i][j]=0;
                }
            }
            for(j=0;j<2;j++)
                if(T[i][j]>T[i][1-j] + P[i].x[1]-P[i].x[0])
                    T[i][j]=T[i][1-j] + P[i].x[1]-P[i].x[0];
        }
        i--;
        for( d=0x7f7f7f7f;i>0 && Y-P[i].h<=MAX; i--)
            if(P[i].x[0]<=X && P[i].x[1]>=X){
                int t=min(T[i][0]+fabs(P[i].x[0]-X),
                          T[i][1]+fabs(P[i].x[1]-X));
                if(d>t) d=t;
                break;
            }
            if(!i && Y<=MAX) d=0;
        cout<<(d+Y)<<endl;
	}
	return 0;
}