#include <stdio.h>
#include <string.h>
#define MS 1000010
using namespace std;

int A[MS],k;
__int64 amax,amin;
struct HashNode{
    int key;
    int next;
}E[MS];
int hashTable[MS];
int hmax,hmin,end,hashSize;

void hashInit() {
	end=0;
	memset(hashTable, -1, sizeof(hashTable));
	hmax=0;
	hmin=MS;
	hashSize=k;
}

int hash(int k) {
	return (hashSize * (k-amin))/(amax-amin);
}

void hashInsert(int k) {
	int p = hash(k);
	E[end].key = k;
	if(hashTable[p] < 0) {
		E[end].next = -1;
		hashTable[p] = end;		
		if(p>hmax) hmax=p;
		if(p<hmin) hmin=p;//UpdateB(p, 1);
	}
	else {
		int l=p;
		p=hashTable[p];
		if(k>=E[p].key)	{
			E[end].next=hashTable[l];
			hashTable[l]=end;
		}
		else {
			while(p>=0 && k<E[p].key) {
				l=p;
				p=E[p].next;
			}
			E[end].next = E[l].next;
			E[l].next = end;
		}
	}
	end++;
}

void hashDelete(int k) {
	int p = hash(k);
	int l = p;
	p=hashTable[p];
	if(E[p].key==k) {
		hashTable[l] = E[p].next;
		if(hashTable[l] < 0){
			p=l;
			if(p==hmax) {
			while(p>0 && hashTable[p]<0) p--;
			hmax=p;
			}
			if(p==hmin) {
			while(p<=hashSize && hashTable[p]<0) p++;
			hmin=p;
			}//UpdateB(l, 0);
		}
	}
	else {
		while(E[p].key != k) {
			l=p;
			p=E[p].next;
		}
		E[l].next=E[p].next;
	}
}

int findMax()
{
 	int p=hmax;
	p=hashTable[p];
 	if(p < 0) {
		return 0;
	}
	return E[p].key;
}

int findMin()
{
 	int p=hmin;
	p=hashTable[p];
 	if(p < 0) {
		return 0;
	}
	while(E[p].next >= 0) {
		p=E[p].next;
	}
	return E[p].key;
}

int main()
{
	int n,i,j;
 	scanf("%d%d", &n, &k);
	hashInit();
	
	scanf("%d", A+1);
	amax=(amin=A[1]);
 	for(i=2; i<=n; i++)
 	{
	 	scanf("%d", A+i);
		if(A[i]>amax) amax=A[i];
		if(A[i]<amin) amin=A[i];
	}
	for(j=1; j<k; j++)
		hashInsert(A[j]);
	for(i=1; j<n; i++, j++)
	{
		hashInsert(A[j]);
		A[i-1]=findMax();
		printf("%d ",findMin());
		hashDelete(A[i]);
	}
	hashInsert(A[j]);
	A[i-1]=findMax();
	printf("%d\n",findMin());

	for(i=0; i<n-k; i++)
		printf("%d ",A[i]);
	printf("%d\n",A[i]);
	scanf("%d", A);
	return 0;
}


