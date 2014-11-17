#include <iostream.h>
long long a,b,c;
int main()
{
  cin>>a;  
  b=2*a;
  while((b*b+1)%(a-b))b--;
  cout<<(b*b+1)/(b-a);
  return 0;
}

