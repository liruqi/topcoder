
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int flag;
    stack<string> back;
    stack<string> next;
   
    string temp="http://www.acm.org/";
    string current;
    while(getline(cin,current))
    {
           if(current=="QUIT") 
           break; 
           
           else if(current=="BACK")
           {
               if(back.empty())
               cout<<"Ignored"<<endl;
               else
               {
               cout<<back.top()<<endl;  
               next.push(temp);
               temp = back.top(); 
               back.pop(); 
               }            
           } 
           
            else   if(current=="FORWARD")
            {
               if(next.empty())
               cout<<"Ignored"<<endl;
               else
               {
                   cout<<next.top()<<endl;
                   back.push(temp);
                   temp = next.top();
                   next.pop(); 
               }  
            }
            
            else if(flag=current.find("VISIT") != string::npos)
            {
              flag = current.find_last_of(" ");
              back.push(temp);
              temp = current.substr(flag+1) ;
              while(!next.empty()) next.pop();
              cout<<temp<<endl; 
            } 
    }
    
    return 0;
}
