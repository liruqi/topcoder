#include<algorithm>
#include<stdio.h>
using namespace std;
#define maxn 100100

int a[maxn][6];
int idx[maxn], n;
void
uniform(int i){
    int b[6],j;
    int *c=a[i];
    copy(c,c+6,b);
    for(j=0;j<6;j++){
        rotate(b,b+1,b+6);
        if(lexicographical_compare(b, b+6, c, c+6))
            copy(b,b+6,c);
    }
    reverse(b,b+6);
    for(j=0;j<6;j++){
        rotate(b,b+1,b+6);
        if(lexicographical_compare(b, b+6, c, c+6))
            copy(b,b+6,c);
    }
    //for(j=0;j<6;j++)cout<<a[i][j]<<" ";cout<<endl;
}

bool ident(int i1, int i2){
	int i;
	for(i=0;i<6;i++)
		if(a[i1][i]!=a[i2][i])
			return 0;
	return 1;
}

bool cmp(int p, int q){
    return lexicographical_compare(a[p], a[p]+6, a[q], a[q]+6);
}
bool found(){
    int i;
    sort(idx, idx+n, cmp);
    for(i=1;i<n;i++)
        if(ident(idx[i-1], idx[i]))
            return 1;
    return 0;
}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<6;j++)
            scanf("%d",a[i]+j);
        uniform(i);
        idx[i]=i;
    }
    puts(found()?"Twin snowflakes found.":"No two snowflakes are alike.");
	return 0;
}
