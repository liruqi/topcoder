#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <map>
#include <cmath>
using namespace std;
const char end[]="----------";
char str[251];
char buf[251];
void filter()
{
	int i=0, j=0;
	
 	for(; buf[i]!='\0'; i++)
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
	str[j]='\0';
}

int main()
{
 	map<string, int> searchs;
	map<string, int>::iterator strit;
	while(scanf("%s",buf)){
		if(strcmp(buf, end)==0)
		    break;
		filter();
		if(str[0]=='\0')
		    continue;
		searchs[str]++;
	}
 
	bool single=0;
	map<string, int> docu;
	while(scanf("%s",buf))
	{
	 	if(strcmp(buf, end)==0){
	 	    if(single) return 0;
			double res=0;
			int cnt;
			single=1;
			for(strit=searchs.begin(); strit!=searchs.end(); ++strit)
			{
		        cnt=strit->second * docu[strit->first];
		        res+=sqrt(cnt);
			}
			printf("%.2lf\n",res);
			docu.clear();
		}
		else {
			filter();
			if(str[0]=='\0') continue;
	 	 	docu[str]++;
	 	 	single=0;
		}
    }
}
