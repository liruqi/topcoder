/*
Problem: Sudoku
Algorithm: dance link
Author: Liruqi
Date: 2008-6-28
*/

#include<set>
#include<iostream>
#include<vector>
using namespace std;

#define MAXSD 9
#define ssz 3
#define side MAXSD
typedef set<int> link;
typedef link::iterator lii;

link lnk[MAXSD][MAXSD];
int sta[MAXSD][MAXSD];
int depth;

void fill_lnk(int _r,int _c){
	bool vst[MAXSD+1];
	memset(vst+1,0,side);
	for(int r=0;r<side;r++)
        vst[sta[r][_c]]=1;
	for(int c=0;c<side;c++)
        vst[sta[_r][c]]=1;
	int br=_r/ssz*ssz;
	int bc=_c/ssz*ssz;
	for(int a=0;a<ssz;a++)for(int b=0;b<ssz;b++){
		int r=br+a;
		int c=bc+b;
        vst[sta[r][c]]=1;
	}
	lnk[_r][_c].clear();
	for(int p=1;p<=side;p++)
	    if(!vst[p])
	        lnk[_r][_c].insert(p);
	#ifdef debug
    show(_r);
    show(_c);
    show(lnk[_r][_c].begin(), lnk[_r][_c].end());
    #endif
}

/*
find a position minimum possible values
stored in _r, _c
*/
void find_min(int& _r,int& _c){
	_r=-1;
	for(int r=0;r<side;r++)
	for(int c=0;c<side;c++)
	    if(sta[r][c]==0){
			if(lnk[r][c].empty())
			{
				_r=-2;
				return;
			}
			if(_r<0) {
				_r=r;
				_c=c;
			} else {
				if(lnk[r][c].size() < lnk[_r][_c].size()) {
					_r=r;
					_c=c;
				}
			}
		}
}

bool find_dfs(){
	
	//show(depth);
	int _r,_c;
	find_min(_r,_c);
	if(_r==-2)
		return false;
	if(_r==-1)
		return true;
	link &now=lnk[_r][_c];
	for(lii it=now.begin(); it!=now.end(); ++it){
        vector<int> upd(side);
        //reduce link
        int val=*it;
        for(int r=0;r<side;r++)if(r!=_r)
            if(lnk[r][_c].find(val)!=lnk[r][_c].end())
            {
				upd.push_back((r<<10) + _c);
				lnk[r][_c].erase(val);
			}
		for(int c=0;c<side;c++)if(c!=_c)
		    if(lnk[_r][c].find(val)!=lnk[_r][c].end())
		    {
				upd.push_back((_r<<10) + c);
				lnk[_r][c].erase(val);
			}
		for(int a=0;a<ssz;a++)for(int b=0;b<ssz;b++)
		{
			int r=_r/ssz*ssz+a;
			int c=_c/ssz*ssz+b;
			if(lnk[r][c].find(val)!=lnk[r][c].end())
		    if(r!=_r)
			if(c!=_c){
				upd.push_back((r<<10) + c);
				lnk[r][c].erase(val);
			}
		}
		//dfs
		sta[_r][_c]=val;
		depth++;
		if(find_dfs()) return true;
		depth--;
		sta[_r][_c]=0;
		int len=upd.size();
		for(int idx=0;idx<len;idx++){
			int r=upd[idx]>>10;
			int c=upd[idx]& 0x3ff;
			lnk[r][c].insert(val);
		}
	}
	return false;
}

int main(){
	char buf[99];
	int r,c,ks;
	scanf("%d",&ks);while(ks--){
		for(r=0;r<side;r++)
		for(scanf("%s",buf),c=0;c<side;c++)
		sta[r][c] = buf[c]-'0';
		
		for(r=0;r<side;r++)
		for(c=0;c<side;c++)
		if(!sta[r][c])
			fill_lnk(r,c);
		depth=0;
		if(!find_dfs()){
			puts("Incorrect");
			return 0;
		}
		for(r=0;r<side;r++,puts(""))
		for(c=0;c<side;c++)printf("%d",sta[r][c]);
}
}
