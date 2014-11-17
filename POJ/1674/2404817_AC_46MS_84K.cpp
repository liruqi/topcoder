#include<cstdio>
#include<algorithm>
using namespace std;

int A[100001];
int main(){
    int T,N,i,j; scanf("%d",&T);
    while(T--){
        int cnt=0;
        scanf("%d",&N);
        for(i=1;i<=N;i++){
            scanf("%d",A+i);
        }
        for(i=1;i<=N;i++){
            while(A[i]!=i)
            {   
                j=A[i]; 
                swap(A[i],A[j]);
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
