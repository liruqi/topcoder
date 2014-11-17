int r[1501];
int Min(int a,int b,int c){
    if(a<b)b=a;
    if(b<c)c=b;
    return c;
}    
int main(){
    int a;
    int b;
    int c;
    int i;
    int j;
    
    r[1]=1;r[2]=2;r[3]=3;r[4]=4;r[5]=5;
    a=3; b=2;  c=2;  
    for(i=6;i<=1500;i++){
        r[i]=Min(r[a]*2,r[b]*3,r[c]*5);
        for(;r[a]*2<=r[i];a++);
        for(;r[b]*3<=r[i];b++);
        for(;r[c]*5<=r[i];c++);
    }
    scanf("%d",&i);
    while(i){
        printf("%d\n",r[i]);
        scanf("%d",&i);
    }
    return 0;
}
