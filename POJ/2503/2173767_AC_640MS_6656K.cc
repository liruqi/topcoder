#include<cstdio>
#include<map>
using namespace std;
struct ltstr{
	bool operator() (const char* a,const char* b)const
	{return strcmp(a,b)<0;}
};
map<char*,char*,ltstr> dict;
char line[10000],dt[100001][11];
int p=0;
int main()
{
	while(gets(line) && line[0])
	{
		char *br=strchr(line,' ');
		*br=0;
		strcpy(dt[p],br+1);
		dict[dt[p++]]=strdup(line);
	}
	map<char*,char*,ltstr>::iterator it;
	while(scanf("%s",line)!=EOF)
		if((it=dict.find(line))!=dict.end())
			printf("%s\n",it->second);
		else
			puts("eh");	
	return 0;
}
