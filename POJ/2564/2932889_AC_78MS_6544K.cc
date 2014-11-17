//poj1204

#include <stdio.h>
#include <string.h>
#define csize 26
#define maxn 26000
typedef struct _node{
    struct _node *next[csize];
    int cnt;
}node;

node trie, nday[maxn*csize];

char word[csize];
int wl, top;

void addNode(node &cnd, int idx, int len){
    int pos=word[idx]-'a';
    if(idx==wl) {
        cnd.cnt = len;
        return;
    } 
    if(cnd.next[pos]==NULL) {//allocate new space 
        memset(nday+top,0,sizeof(nday[top]));
        cnd.next[pos] = nday+top;
        top++;
    } 
    addNode(*cnd.next[pos], idx+1, len);
}

//cur node, index in word, modified or not
int getlen(node &cnd, int idx, int mdf){
    int ret=1,i;
	int pos=word[idx]-'a';
	if(mdf) {
		if(idx==wl)
			return cnd.cnt+1;
		if(cnd.next[pos]) 
			return getlen(*cnd.next[pos], idx+1, 1);
		return 1;
	}
    if(idx==wl){//unmodified and leading wl chars are equal
		for(i=0;i<csize;i++) 
			if(cnd.next[i]) 
				ret>?=cnd.next[i]->cnt;
		return ret+1;
	}
	
	if(cnd.next[pos])
		ret = getlen(*cnd.next[pos], idx+1, 0);
	for(i=0; i<csize; i++)
		if(cnd.next[i]&&(i^pos)){
			ret >?= getlen(*cnd.next[i], idx+1, 1);
			ret >?= getlen(*cnd.next[i], idx  , 1);
		}
	ret >?= getlen(cnd, idx+1, 1);//delete this char
	return ret;
} 

int main(){
    int lesl=0;
    memset(&trie,0,sizeof(trie));
    while(~scanf("%s",word)){
        wl = strlen(word);
        int cur = getlen(trie,0,0);
        addNode(trie, 0, cur);
		//printf("%d\n", cur);
		lesl >?= cur;
    }
    printf("%d\n", lesl);
} 
