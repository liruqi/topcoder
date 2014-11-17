#include<list>
#include<cstdio>
#include<cstring>

using namespace std;
#define MAXL 128
struct elem{
    int idx, val;
};
typedef list<elem> sit;
bool fd;
struct array{
    sit ass;
    int len;
    bool dec;
}var[MAXL];

char buf[100];

int get_val(int left,int right){
    int ret=-1;
    int name=buf[left];
    if( isdigit(name) ) {
        sscanf(buf+left, "%d%*s",&ret);
        return ret;
    }
    array &now=var[name];
    int idx=get_val(left+2, right-1);
    sit::iterator it;
    for(it=now.ass.begin(); it!=now.ass.end();++it)
        if(it->idx == idx) break;
    if(now.dec && (it!=now.ass.end()))
        return (it->val);
    fd=1;
    return ret;
}

void check(){
    int i;
    int pos=-1;
    int len=strlen(buf);
    for(i=0;i<len;i++) 
        if(buf[i]=='='){
            pos=i;
            break;
        }
    int name=buf[0];
    array &now = var[name];
    if(pos<0){
        now.len = get_val(2,len-1);
        now.dec = 1;
        return;
    }
    int left_idx = get_val(2, pos-1);
    int right_val = get_val(pos+1, len);
    if((!now.dec) || (left_idx >= now.len))
        fd=1;
    else
        now.ass.push_front((elem){left_idx, right_val});
}

int main(){
	while(1){
        fd=0;
        int i;
        for(i=0;i<MAXL;i++)
            var[i].dec=0, var[i].ass.clear();
	for(i=1;;i++){
            gets(buf);
            if(buf[0]=='.') 
                break;
            if(fd) 
                continue;
            check();
            if(fd) 
                printf("%d\n",i);
	}
	if(i==1) break;
	if(!fd) puts("0");
	}
}
