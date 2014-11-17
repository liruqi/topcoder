#include <string>
#include <iostream>
#include <cstring>
using namespace std;

char buf[1000];
int idx[5],top;
int main(){
int ks,i,j;
string s1,s2,s3,s4,s5;
cin>>ks;getchar();
while(ks--){
top=0;
cin.getline(buf,1000);
j=strlen(buf);
for(i=0;i<j;i++){
if(buf[i]=='<'||buf[i]=='>')idx[top++]=i;
}
s1=string(buf, buf+idx[0]);
s2=string(buf+idx[0]+1, buf+idx[1]);
s3=string(buf+idx[1]+1, buf+idx[2]);
s4=string(buf+idx[2]+1, buf+idx[3]);
s5=string(buf+idx[3]+1, buf+j);
cin.getline(buf,1000);
cout<<s1<<s2<<s3<<s4<<s5<<endl;
cout<<string(buf,buf+strlen(buf)-3)<<s4<<s3<<s2<<s5<<endl;
}
}