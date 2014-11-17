#include<stdio.h>
int row,col,i,j,k;
void prt(int n){
	if(!n)return;
	n--;
	prt(n/26);
	putchar(n%26+'A');
}
void sol(){
	prt(col);
	printf("%d\n",row);
}
int main(){
	while(EOF!=scanf("R%dC%d\n",&row,&col) && (row&&col)) 
		sol();
}
