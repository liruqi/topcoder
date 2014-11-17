/*
Problem: Sudoku Checker
Author: Liruqi
Date: 9:11 2008-6-30
*/

#include<set>
#include<iostream>
#include<vector>
using namespace std;

//#define debug
template<class T>
void show(T x){cout<<"$ "<<x<<endl;}
template<class T>
void show(T b,T e){cout<<"# "; for(T i=b;i!=e;i++) cout<<*i<<" "; cout<<endl;}
#define MAXSD 100
typedef set<int> link;
typedef link::iterator lii;

link lnk[MAXSD][MAXSD];
int ssz, side, sta[MAXSD][MAXSD];
int depth;

void fill_lnk(int _r,int _c){
	bool vst[MAXSD+1];
	memset(vst+1,0,side);
	for(int r=0;r<side;r++)if(r!=_r)
        vst[sta[r][_c]]=1;
	for(int c=0;c<side;c++)if(c!=_c)
        vst[sta[_r][c]]=1;
	int br=_r/ssz*ssz;
	int bc=_c/ssz*ssz;
	for(int a=0;a<ssz;a++)for(int b=0;b<ssz;b++){
		int r=br+a;
		int c=bc+b;
		if(r!=_r && c!=_c)
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

int main(){
	cin>>ssz;
	side = ssz*ssz;
	int r,c;
	bool err=0;
	for(r=0;r<side;r++)
	for(c=0;c<side;c++)
		cin>>sta[r][c];
	for(r=0;r<side;r++)
	for(c=0;c<side;c++)
		if(sta[r][c]){
			fill_lnk(r,c);
			if(lnk[r][c].find(sta[r][c]) == lnk[r][c].end())
				err=1;
		}
	depth=0;
	puts(err?"INCORRECT":"CORRECT");
}
