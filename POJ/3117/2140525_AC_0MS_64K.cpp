#include <iostream.h>

char str[5];
int main()
{
int n,m,cnt,tot=0,t;
while(cin>>n>>m && n)
{
cnt=0;
for(int i=0; i<n; i++)
{
cin>>str>>t;
cnt+=t;
}
cout<<(3*m-cnt)<<endl;
}
return 0;
}
