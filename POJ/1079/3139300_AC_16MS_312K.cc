#include<algorithm>
#include<stdio.h>
using namespace std;

typedef long long ll;
int num, den;
int main(){
        while( ~scanf("%d%d",&num,&den) ) {
                int cd=__gcd(num,den);
                num/=cd;
                den/=cd;
                int i,j,r;
                pair<int,int> last;
                r = num%den;
                last.first = num/den + (r*2>=den?1:0);
                last.second = 1;
                printf("%d/%d\n",last.first,last.second);
                for(i=2;i<=den;i++){
                        int j=i*num/den;
                        int r=i*num%den;
                        if(r*2 >= den) j++;
                        pair<int,int> now(j,i);
                        pair<ll, ll> le(abs(num*last.second-den*last.first), den*last.second);
                        //printf("* %d/%d  %lld/%lld  ???  ",j,i,le.first,le.second);
                        pair<ll, ll> ne(abs(num*now.second-den*now.first), den*now.second);
                        //printf("%lld/%lld\n",ne.first,ne.second);
                        if(ne.first*le.second < ne.second*le.first) {
                                last=now;
                                printf("%d/%d\n",now.first,now.second);
                        }
                        
                }puts("");
        }
}
