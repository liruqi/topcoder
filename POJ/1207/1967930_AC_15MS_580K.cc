#include <iostream>
#define MS 100000
using namespace std;
int A[MS];

int CycleLength(int n){
	if(n==1) return 1;
	if(n%2)	n = 3*n+1;
	else n = n/2;
	
	if(n<MS && !A[n]) {
		A[n]=CycleLength(n);
    	return (1 + A[n]);
	}
	else return 1 + CycleLength(n);
}

int main()
{
 	int up, low, i, maxInd;
	while(cin>>low>>up){
		cout<<low<<" "<<up<<" ";
		if(low>up){
			i=low;
			low=up;
			up=i;
		}	   
		maxInd = low;
		A[low] = CycleLength(low);
		for(i=low+1; i<=up; i++)
		{
			A[i] = CycleLength(i);
			if(A[i] > A[maxInd])
				maxInd = i;
			//cout<<"A"<<i<<" value:"<<A[i]<<endl;	
		}
		cout<<A[maxInd]<<endl;
	}
	
	return 0;
}
