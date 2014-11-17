#include<stdio.h>
int r[5850];
int Min(int a,int b,int c,int d){
    int m=a;
    if(b<m)m=b;
    if(c<m)m=c;
    if(d<m)m=d;
    return m;
}
int main(){
    int a, b, c, d;
    int i, j;
    for(i=0; i<8; i++) r[i]=i;
    a=4; b=3; c=2; d=2;
    for(i=8;i<=5842;i++){
        r[i]=Min(r[a]*2,r[b]*3,r[c]*5,r[d]*7);
        for(;r[a]*2<=r[i];a++);
        for(;r[b]*3<=r[i];b++);
        for(;r[c]*5<=r[i];c++);
		for(;r[d]*7<=r[i];d++);
    }
    
    while(scanf("%d",&i)==1 && i){
		printf("The %d",i);
		switch(i%10){
			case 1: 
				if(i%100 == 11)printf("th");		
				else printf("st");break;
			case 2: 
				if(i%100 == 12)printf("th");		
				else printf("nd");break;
			case 3: 
				if(i%100 == 13)printf("th");		
				else printf("rd");break;
			default: printf("th");
		}
        printf(" humble number is %d.\n",r[i]);
    }
    return 0;
}

