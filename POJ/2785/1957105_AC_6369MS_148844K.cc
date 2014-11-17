#include <iostream>
#define MS 4000
#define MaxN 32000000
using namespace std;

int N, end, tmp;
int A[4][MS];

struct HashNode{
    int val;
    int cnt;
    int next;
};
int hashTable[MaxN];		
HashNode emem[MaxN/2];		
int hash(int k){
		return (k % (MaxN/2) + MaxN/2);
}
int hashFind(int k)
{
 	int i = hash(k);
 	i = hashTable[i];
 	for(; i!=-1; i=(emem+i)->next)
  		if(k == (emem+i)->val) 
		    return i;
 	return -1;
}

void hashInsert(int k)
{
    int index;
    if ((tmp = hashFind(k)) >= 0) {
  		emem[tmp].cnt ++;
  		return;
    }
    HashNode *p = emem+end;
    p->val = k;
    index = hash(k);
    p->next = hashTable[index];
    hashTable[index] = end;
    p->cnt = 1;
	end++;
    return;
}

int main()
{
 	int i,j,key;
 	memset(hashTable, -1, sizeof(hashTable));
	cin>>N;
 	for(i=0; i<N; i++)
	    for(j=0; j<4; j++)
  		    cin>>A[j][i];
    for(i=0; i<N; i++)
	    for(j=0; j<N; j++)
  		    hashInsert(A[0][i]+A[1][j]);
    int ans = 0;
    for(i=0; i<N; i++)
	    for(j=0; j<N; j++)
	    {
		 	key = - A[2][i] - A[3][j];
			if( (tmp = hashFind(key))!=-1 ) 
			{
			 	ans += (emem+tmp)->cnt;
			}
		}
	cout<<ans<<endl;
	return 0;
}
