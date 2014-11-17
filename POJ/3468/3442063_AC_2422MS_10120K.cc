#include<stdio.h>
#include<algorithm>
using namespace std;
#define mx 400000


typedef long long ll;
int n,q;
ll org[mx],ps[mx];

struct segTree{
	ll sum[mx],rud[mx];
	int lb[mx],rb[mx],md[mx],len[mx];
	inline int left_ch(int x){return 2*x;}
	inline int right_ch(int x){return 2*x+1;}
	
	void build_tree(int lt,int rt,int p)
	{
	    lb[p]=lt;
	    rb[p]=rt;
	    md[p]=(lt+rt)/2;
	    len[p]=rb[p]-lb[p]+1;
	    if(lt==rt)
	    {
	        return;
	    }
	    build_tree(lt,md[p],2*p);
	    build_tree(md[p]+1,rt,2*p+1);
	}
	
	ll range_update(int lt,int rt,ll val,int p){
		ll ret=0,add;
	    if(lt<=lb[p] && rt>=rb[p]){
			rud[p]+=val;
			ret=val*len[p];
			sum[p]+=ret;
			return ret;
		}
	    if(lt<=md[p]){
	        add=range_update(lt,rt,val,2*p);
	        ret+=add;
		}
	    if(rt>md[p]){
	        add=range_update(lt,rt,val,2*p+1);
	        ret+=add;
		}
		sum[p]+=ret;
		return ret;
	}
	
	ll range_query(int lt,int rt,int p){
	    if(lt<=lb[p] && rt>=rb[p]){
			return sum[p];
		}
		ll ret=0;
		if(lt<=md[p]){
	        ret+=range_query(lt,rt,2*p);
	        ret+=rud[p]*(min(rt,md[p])-max(lt,lb[p])+1);
		}
	    if(rt>md[p]){
	        ret+=range_query(lt,rt,2*p+1);
	        ret+=rud[p]*(min(rt,rb[p])-max(lt,md[p]+1)+1);
		}
		return ret;
	}
} st;
int main()
{
    scanf("%d",&n);
    scanf("%d",&q);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&org[i]);
        ps[i]=ps[i-1]+org[i];
    }
    st.build_tree(1,n,1);
    int s,t,c;
    while(q--){
        char cmd[3];
        scanf("%s",cmd);
        scanf("%d",&s);
        scanf("%d",&t);
        if(cmd[0]=='C'){
            scanf("%d",&c);
            st.range_update(s,t,(ll)c,1);
        } else {
            printf("%I64d\n",st.range_query(s,t,1)+ps[t]-ps[s-1]);
        }
    }
}
