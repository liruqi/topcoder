#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=50001;
int N, A[maxn], f1[3][maxn], f2[3][maxn];

bool excep(){
    int cnt=0, i;
    int m1=max(A[1],A[2]);
    int m2=A[1]+A[2]-m1;
    for(i=3; i<=N; i++){
        if(A[i]>m2) m2=A[i];
        if(m1<m2) swap(m1, m2);
        if(A[i]>0) cnt++;
    }
    if(cnt>2) return 0;
    cout<<m1+m2<<endl;
    return 1;
}

int main()
{
    int i, m, T;cin>>T;
    while(T-- && cin>>N){
        for(i=1; i<=N; i++)
            scanf("%d",A+i);
        if(excep()) continue;
        for(m=1; m<=2; m++)
        for(i=1; i<=N; i++)
        {
            f1[m][i]=f2[m][i]=0;
            if(i==m) 
                f1[i][i]=f1[i-1][i-1]+A[i];
        }
        for(m=1; m<=2; m++)
        for(i=1; i<=N; i++){
            f2[m][i]=max(f1[m-1][i-1], f2[m][i-1])+A[i];
            f1[m][i]=max(f1[m][i-1],   f2[m][i]  );
        }
        cout<<f1[2][N]<<endl;
    }
    return 0;
}
