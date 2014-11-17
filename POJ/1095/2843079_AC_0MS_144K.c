#define maxn 20
int Catl[maxn];
void tree(int n,int k){
int t=n-1,j;
    if(n<2) {putchar('X');return;}
    for(j=0;j<=t;j++)
        if(k < Catl[j]*Catl[t-j]){
            int Ln=j;
            int Rn=t-Ln;
            int Lk=k/Catl[Rn];
            int Rk=k%Catl[Rn];
            if(Ln>0){
                putchar('('); tree(Ln,Lk); putchar(')');}
putchar('X');
            if(Rn>0){
                putchar('('); tree(Rn,Rk); putchar(')');}
            return;
        }
        else
            k-=Catl[j]*Catl[t-j];
}
int main(){
	int i,j,t,n; 
	Catl[0]=1;
	for(i=1;i<maxn;i++) {
	    for(j=0;j<i;j++)
	    {
            Catl[i]+=Catl[j]*Catl[i-j-1];
        }
    }
	while(~scanf("%d",&n) && n){
        for(t=0;t<maxn;t++)
        if(n<Catl[t])
            break;
        else
            n-=Catl[t];
        tree(t,n);puts("");
    }
}
