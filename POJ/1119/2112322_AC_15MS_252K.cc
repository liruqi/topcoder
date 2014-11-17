#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <string.h>
#include <string>
#include <map>
#include <cmath>
using namespace std;
const char end[]="----------";
const char newl='\0';
char str[251];
char buf[251];
void filter()
{
	int i=0, j=0;
	
 	for(; buf[i]!=newl; i++)
	{
		if( isalpha(buf[i]) )
		{
		    str[j++]=tolower(buf[i]);
		}
		else  if( isdigit(buf[i]) )
		{
			str[j++]=buf[i];
		}		
	}
	str[j]=newl;
}

int main()
{
 	map<string, int> searchs;
	map<string, int>::iterator strit;
 	string cpps;
 	while(cin>>buf){
		if(strcmp(buf, end)==0)
		    break;
		filter();
		if(str[0]==newl)
		    continue;
		cpps=str;
		searchs[cpps]++;
	}
 	//document
	bool single=0;
	map<string, int> docu;
	while(cin>>buf)
	{
	 	if(strcmp(buf, end)==0){
	 	    if(single) return 0;
			double res=0.0;
			int cnt;
			single=1;
			for(strit=searchs.begin(); strit!=searchs.end(); ++strit)
			{
		        cnt=strit->second * docu[strit->first];
		        res+=sqrt(cnt);
			}				
			cout<<setiosflags(ios::showpoint | ios::fixed)
			    <<setprecision(2)<<res<<endl;
			docu.clear();
		}
		else {
			filter();
			if(str[0]==newl)
			    continue;
			cpps=str;
	 	 	docu[cpps]++;
	 	 	single=0;
		}
    }
}
