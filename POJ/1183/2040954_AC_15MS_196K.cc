#include <iostream>
using namespace std;
long long a,b,c,bpc,tmp;
int main()
{
  cin>>a;
  b=2*a;
  while( (b*b+1)%(a-b) )
    b--;
  bpc=(b*b+1)/(b-a);

  cout<<bpc;
//  system("pause");
  return 0;
}

