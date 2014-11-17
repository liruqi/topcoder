#include <cstdio>
#include <map>
#include <set>
using namespace std;
#define MS 1100000
int A[MS],n;
bool D[MS];
int main()
{
    int i;
    scanf("%d",&n);
    while(n){
        memset(D,0,MS);
        set<int> is;
        for(i=1;i<=n;i++) {
            scanf("%d",A+i);
            is.insert(A[i]);
        }
        int maxN=is.size();
        int head=1,tail=1,cnt=0,minlen=n;
        map<int, int> im;
        for(head=1;head<=n;head++) {
            if(im[A[head]]==0){
                cnt++;
            }
            else {
                int li=im[A[head]];
                D[li]=1;
                if(li==tail){
                    while(D[tail]) tail++;
                }
            }
            if(cnt==maxN)
                if(head-tail+1<minlen)
                    minlen=head-tail+1;
            im[A[head]]=head;
        }

        printf("%d\n",minlen);
        if(EOF == scanf("%d",&n)) return 0;
    }
    return 0;
}

/*
9
1 8 8 8 1 2 8 8 8

1
1

2
1 2

9
8 1 8 8 2 2 8 8 8
*/
