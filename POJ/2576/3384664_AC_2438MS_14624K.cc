#include<set>
#include<iostream>
using namespace std;

set<int> stt[450*100/2 + 10];
int wgt[110];
int main(){
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>wgt[i],sum+=wgt[i];
	int half_sum = (sum)/2;
	int half_num = (n+1)/2;
	stt[0].insert(0);
	int bound=0;
	for(int i=0;i<n;i++)
		for(int j=half_sum-wgt[i];j>=0;j--){
			int k=j+wgt[i];
			set<int> &now = stt[j];
			for(set<int>::iterator it=now.begin();it!=now.end();++it)
			{
				if(*it < half_num){
					stt[k].insert(*it+1);
				}
			}
		}
	for(int i=half_sum;i;i--){
		if(stt[i].size()){
			int large= *(--stt[i].end());
			if(large==half_num || (n%2 && large==half_num-1))
			{
				cout<<i<<" "<<sum-i<<endl;
				break;
			}
		}
	}
}
