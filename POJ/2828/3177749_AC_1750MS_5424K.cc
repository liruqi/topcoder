#include <stdio.h>

#define mx 200000
int A[mx], B[mx];

int T[mx*4], V[mx*4], val,N;

//[left, right)

void init(int left,int right,int p){

    if(left>=right) return;
    //printf("*pos:　[%d %d) -> %d\n",left, right, p);

    T[p]=right-left;

    if(left+1==right) return;

    int mid = (left+right+1)/2;

    init(left, mid, 2*p);

    init(mid, right, 2*p+1);

}


void prtt(int left,int right,int p){
	if(left>=right) return;
	//printf("[%d %d) -> %d\n",left, right, V[p]);

    if(left+1==right) {
		printf("%d%c",V[p],right<N?' ':'\n');
    	return;
    }

    int mid = (left+right+1)/2;

    prtt(left, mid, 2*p);

    prtt(mid, right, 2*p+1);

}


void addt(int left,int right,int k,int p){

    if(left>=right) return;
    //printf("pos:　[%d %d) -> %d\n",left, right, k);

    if(left+1==right){
		T[p]=0;

        V[p]=val;

        //printf("*V[%d] = %d\n", p, val);

        return;

    }

    int mid = (left+right+1)/2;

    if(k<T[2*p]) addt(left, mid, k, 2*p);

    else addt(mid, right, k-T[2*p], 2*p+1);

    T[p]--;

}



int main(){

    int i;

    while(-1!=scanf("%d",&N)){

        init(0,N,1);

        //memset(V,-1,sizeof(V));

        for(i=0;i<N;i++)

            scanf("%d%d",A+i,B+i);
        for(i=N-1;i>=0;i--)
        	val=B[i],addt(0,N,A[i],1);

        //for(i=0;i<N;i++)printf("%d ",V[i]);
		prtt(0,N,1);


    }

    return 0;

}


