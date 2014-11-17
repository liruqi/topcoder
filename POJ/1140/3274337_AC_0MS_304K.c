int v[1100];
int stk[1100],top;
int main(){
	int i, num, den;
	while(scanf("%d%d",&num,&den), den){
        memset(v,0,sizeof(v));
        top=0;
        int rem=num;
        int term=0;
        do{
            if(v[rem]) {term=top+1-v[rem];break;}
            stk[top++]=rem*10/den;
            v[rem]=top;
            rem=rem*10%den;
        }while(rem);
        putchar('.');
        for(i=0;i<top;i++){
            if(i%50==49) puts("");
            printf("%d",stk[i]);
        }
        puts("");
        if(!term) {
            puts("This expansion terminates.");
            continue;
        }
        printf("The last %d digits repeat forever.\n",term);
    }
}
