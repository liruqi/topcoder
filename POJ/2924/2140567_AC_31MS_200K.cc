#include <iostream>
using namespace std;

int main()
{
long long n, m;
int tc=1;
cin>>n;
while(cin>>n>>m)
{
cout<<"Scenario #"<<tc++<<":"<<endl
    <<( (m-n+1)*(m+n)/2 )<<endl<<endl;
}
return 0;
}
