#include<stdio.h>
#include<string.h>

char n1[5],n2[5],v1[5],v2[5];


int main(){
int i,j,ks;
scanf("%d",&ks);
while(ks--){
int a=0,b=0;
scanf("%s",n1);
scanf("%s",n2);
memset(v1,0,sizeof(v1));
memset(v2,0,sizeof(v2));
for(i=0;i<4;i++)
if(n1[i]==n2[i])
v1[i]=1,v2[i]=1,a++;

for(i=0;i<4;i++)if(!v1[i])
for(j=0;j<4;j++)if(!v2[j])
if(n1[i]==n2[j])
v1[i]=1,v2[j]=1,b++;

printf("%dA%dB\n",a,b);
}//end while
}