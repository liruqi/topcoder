#include <iostream.h>
#include <iomanip.h>
const int maxn = 101;
struct task{
	double size;
	double spd;
	double tm;
	double ms;
}T[maxn];
double bw;//bandwidth
bool uf[maxn];
bool rc[maxn];
int N, taskNum;
//precondition: total task have not finished yet
int findNext()
{
	int i=1, mtid;	//min time id
	while(! uf[i]) i++;
	mtid=i;
	for(i++; i<=N; i++) if(uf[i])
	{
		if(T[i].size/T[i].spd < T[mtid].size/T[mtid].spd)
			mtid=i;
	}
	return mtid;
}

void divide(double totspd, int num)
{
	int i, nn=num;
	double extra=totspd/(double)num;
	for(i=1; i<=N; i++) if(rc[i])
		T[i].spd+=extra;

	extra=0;
	for(i=1; i<=N; i++) if(rc[i])
		if(T[i].spd > T[i].ms)
		{
			extra+=T[i].spd - T[i].ms;
			T[i].spd=T[i].ms;
			rc[i]=0;
			nn--;
		}
    if(nn == num) return;
	if(nn) divide(extra, nn);
}

int main()
{
	int i, fin, tc=1;
	while(cin>>N && N)
	{
		cin>>bw;
		for(i=1; i<=N; i++){
			cin>>T[i].size
			   >>T[i].spd
			   >>T[i].ms;
			T[i].tm=0;
			uf[i]=1;
		}
		taskNum=N;
		//end of case input
		while(taskNum)
		{
			fin = findNext();
			double ftm=T[fin].size/T[fin].spd;
			double spare=bw;
			for(i=1; i<=N; i++) if(uf[i])
			{
				T[i].tm += ftm;
				T[i].size -= ftm*T[i].spd;
			}
			uf[fin]=0;
			taskNum--;
			for(i=1; i<=N; i++)
			{
				rc[i]=uf[i];
				if(uf[i]) spare-=T[i].spd;
			}
			divide(spare, taskNum);

		}
		cout<<"Case "<<tc++<<':'<<endl;
		for(i=1; i<=N; i++){
			cout<<"NO"<<i<<':'
				<<setiosflags(ios::showpoint | ios::fixed)
				<<setprecision(3)
				<<T[i].tm<<'s'
				<<endl;
		}
	}
	return 0;
}
