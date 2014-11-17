#include <stdio.h>
#include <string.h>
using namespace std;

char name[32];
int end, leave, cnt;
int i,j;
bool dir;
struct species{
    char na[32];
	int c;
	int left,right;
}sm[10010];						//species in memory

void CreatNode()
{
    strcpy(sm[end].na, name);
    sm[end].c = 1;
    sm[end].left = (sm[end].right  = -1);
    end++;
}

int SearchName(int n)
{
 	if(n >= end)
 	{
		 puts("error");
 	     printf("%d\n",n);
	}
 	if(strcmp(name, sm[n].na) == 0)
        return n;
 	if(strcmp(name, sm[n].na) < 0)
 	{
	 	if( (i = sm[n].left) >= 0 )
	    	return SearchName(i);
        else
		{
		 	dir  = 0;
		  	leave = n;				//也可以用位操作来实现标志 
			return -1;
		}
    }
    if(strcmp(name, sm[n].na) > 0)
 	{
	 	if( (i = sm[n].right) >= 0 )				  
	    	return SearchName(i);
        else
		{
		 	dir = 1;
		  	leave = n; 
			return -1;
		}
    }
}

void AddNode()
{
 	if(dir)
	    sm[leave].right = end;
 	else
	    sm[leave].left = end;
}

void PrintRes(int n)			//中序遍历 
{
 	if(sm[n].left >= 0)
	    PrintRes(sm[n].left);
    printf("%s %.4f\n",sm[n].na, (double)(sm[n].c*100) / (double)cnt );
    if(sm[n].right >= 0)
	    PrintRes(sm[n].right);
}

int main()
{
 	int pos;
 	end = 0;
    cnt = 1;
    gets(name);
    CreatNode();
 	while(gets(name) != NULL)
 	{
	    cnt++;
	    if( (pos = SearchName(0)) >= 0 )
	    	sm[pos].c ++;
		else {
	        AddNode();
			CreatNode();
	    }
    }
    PrintRes(0);
    gets(name);
 	return 0;
}
 	//printf("%d",1<<16);
