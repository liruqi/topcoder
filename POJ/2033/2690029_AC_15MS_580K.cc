#include <iostream>
#include <string>
using namespace std;
main(){
   string s;
   int a[60000];
   while(cin>>s&&s[0]!='0'){
      int l=s.length();
      int cnt=1;
      a[1]=1;
      a[0]=1;
      for(int i=1;i<l;i++){
         if(s[i]=='0')  { a[i+1]=a[i-1]; }
         else{
            if((s[i-1]-'0')*10+s[i]-'0'<=26&&(s[i-1]-'0')*10+s[i]-'0'>=1&&s[i-1]!='0'){
               a[i+1]=a[i]+a[i-1];         
            }
            else  a[i+1]=a[i];
         }
      }
      cout<<a[l]<<endl;
   }
   return 1;
}