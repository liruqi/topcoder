#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char A[1000][20];
unsigned int tc=1, tot;
//int L[1000];

int cmp(const void *a, const void *b){
	char *aa=(char *)a, *bb=(char *)b;
	int al=strlen(aa);
	int bl=strlen(bb);
	return al-bl;
}

int prefix(int i, int j){
	int k;
	for(k=0; A[i][k]!='\0'; k++) 
		if(A[i][k]!=A[j][k]) 
			return 0;
	return 1;
}

int dec(){
	unsigned int i,j;
	for(i=0; i<tot; i++)
		for(j=i+1; j<tot; j++)
			if(prefix(i, j))
				return 0;
	return 1;
}

int main()
{
	int i=0;
	while(gets(A[i])){
		while(A[i][0]!='9')
		{
		i++;
		gets(A[i]);
		}
		tot=i+1;
		qsort(A, tot, sizeof(A[0][0])*20, cmp);
		if(dec()) printf("Set %d is ",tc);
		else printf("Set %d is not ",tc);
		puts("immediately decodable");
		tc++;
		i=0;
	}
	return 0;
}