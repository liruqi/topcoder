#include <iostream>
using namespace std;

int H[11000];

int main()
{
    int N,d,c;
    while(scanf("%d",&N) && N){
        memset(H,0,10000*4);
        for(int i=0;i<N;i++) {
            scanf("%d%d",&d,&c);
            if(H[d]>0)
                H[d]=min(H[d],c);
            else
                H[d]=c;
        }
        
        int cnt=0,curm=11000;
        for(int i=1;i<=10000;i++) 
            if(H[i]>0 && H[i]<curm){
                cnt++;
                curm=H[i];
            }
        printf("%d\n",cnt);
    }
    return 0;
}
