#include <stdio.h>
#include <math.h>

#define maxn 200001
int A[maxn], head,tail;
int N,K;
char F[maxn];
void enqu(int n){
    //cout<<"enqu: "<<n<<endl;
    A[tail++]=n;
    F[n]=1;
}

int dequ(){
    //cout<<"dequ: "<<A[head]<<endl;
    return A[head++]; 
}

int Step(){
    int sp=0,i;
    if(N>=K) return N-K;
    head=tail=0;
    enqu(N);
    
    while(!F[K]){
        int st=head, ed=tail;
sp++;
        for(i=st;i<ed;i++){
            int tn=dequ();
            
            if(tn+1<2*K&&!F[tn+1]) enqu(tn+1);
            if(tn-1<2*K&&!F[tn-1]) enqu(tn-1);
            if(tn<=K && !F[2*tn]) enqu(2*tn);
        }
    }
	return sp;
}

int main()
{
    scanf("%d%d",&N,&K);
    printf("%d",Step());
    return 0;
}
