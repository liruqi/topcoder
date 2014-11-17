#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int A[50];

int main(){
	int i,j,n,s,p; while(cin>>n && n>0){
        for(s=0,i=1;i<=n;i++) cin>>A[i],s+=A[i];
        for(p=0,i=1;p*2<s&&i<=n;i++) {
            p+=A[i];
        }
        if(s==2*p)
            printf("Sam stops at position %d and Ella stops at position %d.\n",i-1,i);
        else puts("No equal partitioning.");
    }
}
