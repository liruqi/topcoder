#include<algorithm>
#include<iostream>
#include<list>
using namespace std;

int rowA,rowB,colA,colB,r,c;
char ia[21][21],ib[21][21],it[21][21];

int equal(int lt){
	int rr;
	for(rr=0;rr<rowA;rr++)
		if(ia[rr][c]!=it[rr][lt])
			return 0;
	return 1;
}

//compare col
int compare(){
	int last=0;
	for(c=0;c<colA;c++){
		for(;last<colB && !equal(last);last++);
		if(last==colB)
			return 0;
	}
	return 1;
}

int main(){

	scanf("%d",&rowA);
	scanf("%d",&colA);
	for(r=0;r<rowA;r++)
		scanf("%s",ia[r]);
	scanf("%d",&rowB);
	scanf("%d",&colB);
	for(r=0;r<rowB;r++)
		scanf("%s",ib[r]);
	
	int i,k;
	for(k=0;k<(1<<rowB);k++)
		if(__builtin_popcount(k)==rowA){
			i=0;
			for(r=0;r<rowB;r++) if(k & (1<<r))
				memcpy(it[i++],ib[r],colB);
			if(compare()){
				//printf("%d",k);
				puts("Yes");
				return 0;
			}
		}
	puts("No");
}
