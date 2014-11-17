#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
char str[22];
char sst[22];
int isDic(){
	for(int i=1; str[i]!='\0'; i++)
	if(str[i]==' ')
	{
		str[i]='\0';
		return i+1;
	}
	return 0;
}//end of isDic()

int main()
{
	int pos;
	map<string, string> P;
	gets(str);
	while(str!="" && (pos=isDic()))
	{
		strcpy(sst, str);
		string s1=sst;
		string s2=(str+pos);
		P[s2]=s1;
		gets(str);
	}
	while(scanf("%s",str)!=EOF)
	{
		if(P[(string)str]!="")
		{
			cout<<P[(string)str]<<endl;
		}
		else
			puts("eh");
	}
	return 0;
}
