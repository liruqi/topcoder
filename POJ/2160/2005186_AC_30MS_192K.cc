#include <iostream>
using namespace std;
int end,p[3][2],cnt[3];
bool exist(int x,int y) {
	int i=0;
	for(; i<end; i++)
	    if(x==p[i][0] && y==p[i][1]){
			cnt[i]++;
	    	return true;
		}
	return false;
}

int main()
{
 	int x,y;
 	int i,j;
	bool f=0;
 	while(cin>>x>>y && x>0)
 	{
	 	if(x>y) swap(x,y);
 		if(!exist(x,y)) {
			p[end][0]=x;
			p[end][1]=y;
			cnt[end]=1;
			end++;
		}
	}
	if( !(cnt[0]%2 || cnt[1]%2) )
	switch(end){
	case 1:
		if(p[0][0]==p[0][1]) f=1;
		break;
	case 2:
		i=0;j=1;
		if(p[i][0] == p[i][1] && cnt[i]==2 && cnt[j]==4){	
			if(p[i][0]==p[j][0]||p[i][0]==p[j][1])
			f=1;
		}
		else if(p[j][0] == p[j][1] && cnt[j]==2 && cnt[i]==4){
			if(p[j][0]==p[i][0]||p[j][0]==p[i][1])
			f=1;
		}
		break;
	case 3:
		if(cnt[0]==2&&cnt[1]==2&&cnt[2]==2)
		{
		 	if(p[0][0]==p[1][0]){
				if(p[0][1]==p[2][0] && p[1][1]==p[2][1]) f=1;
				else if(p[0][1]==p[2][1] && p[1][1]==p[2][0]) f=1;
			}
			else if(p[0][0]==p[1][1]){
				if(p[0][1]==p[2][0] && p[1][0]==p[2][1]) f=1;
				else if(p[0][1]==p[2][1] && p[1][0]==p[2][0]) f=1;
			}
			else if(p[0][1]==p[1][0]){
				if(p[0][0]==p[2][0] && p[1][1]==p[2][1]) f=1;
				else if(p[0][0]==p[2][1] && p[1][1]==p[2][0]) f=1;
			}
			else if(p[0][1]==p[1][1]){
				if(p[0][0]==p[2][0] && p[1][0]==p[2][1]) f=1;
				else if(p[0][0]==p[2][1] && p[1][0]==p[2][0]) f=1;
			}
		}
		break;
	}

	if(f) cout<<"POSSIBLE"<<endl;
	else cout<<"IMPOSSIBLE"<<endl;
	return 0;
}

