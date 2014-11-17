
#include <iostream>
#include <math.h>
using namespace std;

int m, n;
struct star{
	double x,y,z;
}S[500];

struct teles{
	double x,y,z;
	double fi;
}T[500];

bool observable(int s, int t)
{
	double v1dv2=S[s].x * T[t].x + S[s].y * T[t].y +S[s].z * T[t].z;
	double v1mv2=(S[s].x*S[s].x + S[s].y*S[s].y + S[s].z*S[s].z) * (T[t].x*T[t].x + T[t].y*T[t].y + T[t].z*T[t].z);
	double cos_theta=v1dv2/sqrt(v1mv2);
	double theta=acos(cos_theta);
	return theta<T[t].fi ? true : false;
}
int main()
{
	int i,j;
	int cnt;
	while(cin>>n && n)
	{
		cnt=0;
		for(i=0; i<n; i++)
			cin>>S[i].x>>S[i].y>>S[i].z;
		cin>>m;
		for(i=0; i<m; i++)
			cin>>T[i].x>>T[i].y>>T[i].z>>T[i].fi;
		for(i=0; i<n; i++) for(j=0; j<m; j++)
		{
			if(observable(i,j))
			{
				cnt++;
				break;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}