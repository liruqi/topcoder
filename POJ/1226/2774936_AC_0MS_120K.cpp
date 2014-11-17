#include <stdio.h>
//#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int t,n;
char str[100][110];
char rev[100][110];
int len[100];
int exist(int sln){
	int i,j;
	for(i=0;i+sln<=len[0];i++){
		string ts(str[0]+i, str[0]+i+sln);
		for(j=1;j<n;j++)
		{
			if( ((string)str[j]).find(ts) != string::npos)continue;
			if( ((string)rev[j]).find(ts) != string::npos)continue;
			break;
		}
		if(j==n) {
			//cout<<ts<<endl;
			return 1;
		}
	}
	return 0;
}

int main(){
	int i,j;
	scanf("%d",&t);
	while(t-- && ~scanf("%d\n",&n)){
		for(i=0;i<n;i++){
			gets(str[i]);
			len[i]=strlen(str[i]);
			reverse_copy(str[i],str[i]+len[i],rev[i]);
			rev[i][len[i]]='\0';
		}
		int low=0,up=100,mid;
		while(low<up){
			mid = (low+up+1)/2;
			//printf("%d\n",mid);
			if(exist(mid))
				low=mid;
			else
				up=mid-1;
		}
		if(exist(low)) up=low;
		printf("%d\n",up);
	}
}
