#include <stdio.h>
#include <string.h>
#define SET_ON 1<<16

char name[32];
int end, leaf, cnt, i;

struct species{
    char na[32];
	int c;
	int left,right;
}sm[10000];	

void CreatNode()
{
    strcpy(sm[end].na, name);
    sm[end].c = 1;
    sm[end].left = (sm[end].right  = -1);
    end++;
}

int SearchName(int n)
{
 	if(strcmp(name, sm[n].na) == 0)
        return n;
 	if(strcmp(name, sm[n].na) < 0)
 	{
	 	if( (i = sm[n].left) >= 0 )
	    	return SearchName(i);
        else
		{
		  	leaf = n;
			return -1;
		}
    }
    if(strcmp(name, sm[n].na) > 0)
 	{
	 	if( (i = sm[n].right) >= 0 )		  
	    	return SearchName(i);
        else
		{
		  	leaf = n | SET_ON;
			return -1;
		}
    }
}

void AddNode()
{
 	if(leaf >= SET_ON){
		leaf -= SET_ON;	
	    sm[leaf].right = end;
    }
 	else
	    sm[leaf].left = end;
}

void PrintRes(int n)
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
 	return 0;
}
