#include <iostream> 
#include <string.h>
#include <algorithm> 
using namespace std; 
bool cmp(char a, char b)
{
 	char c=tolower(a);
 	char d=tolower(b);
 	if(c==d) return (int)a<(int)b;
 	return (int)c<(int)d;
}
int main() 
{ 
   char n[15];
   int len;
   cin>>len;
   while( cin>>n ){
	   len=strlen(n);
	   sort(n, n+len, cmp);
	   cout<<n<<endl;
	   while( next_permutation(n, n + len, cmp) )
	   	  cout<<n<<endl;
   }
   return 0; 
} 
