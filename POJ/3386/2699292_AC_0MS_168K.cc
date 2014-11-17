//3386
#include <stdio.h>
#include <algorithm>
using namespace std;

int ai, ao, bi, bo, P;

int main()
{
	scanf("%d%d%d%d%d",&ao,&ai,&bo,&bi,&P);
	if(ao<bo){
		swap(ao,bo);
		swap(ai,bi);
	}
	if((ai>=bo&&ao<=P) || ao+bo<=P)puts("Yes");
	else puts("No");
}