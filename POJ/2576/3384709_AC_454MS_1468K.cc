#include<iostream>
using namespace std;

bool stt[450*100/2 + 10][51];
int wgt[110];
int main(){
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>wgt[i],sum+=wgt[i];
	int half_sum = (sum)/2;
	int half_num = (n+1)/2;
	stt[0][0]=1;
	
	for(int i=0;i<n;i++)
		for(int j=half_sum-wgt[i];j>=0;j--){
			int k=j+wgt[i];
			for(int c=0;c<=half_num;c++)if(stt[j][c])
			{
				stt[k][c+1]=1;
			}
		}
	for(int i=half_sum;i;i--){
		if(stt[i][half_num] || (n%2 && stt[i][half_num-1])){
			cout<<i<<" "<<sum-i<<endl;
			break;
		}
	}
}
