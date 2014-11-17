#include<iostream>



using namespace std;

#define MSZ 100008



template<class T>

void show(T x){ cout<< "# "<< x <<endl; }

template<class T>

void show(T b,T e){ cout<<"$ "; for(T i=b;i!=e;i++) cout<<*i<<", ";cout<<endl; }



int dat[MSZ], trL[MSZ*4],trR[MSZ*4],trF[MSZ*4];



#define lch(x) (2*(x))

#define rch(x) (2*(x)+1)



int n,q;

void build(int lt,int rt,int p)

{

	//cout<<lt<<" "<<rt<<" "<<p<<endl;

	if(lt==rt)

	{

		trL[p] = (lt>1 && dat[lt-1]==dat[lt]);

		trR[p] = (rt<n && dat[rt]==dat[rt+1]);

		trF[p]=1;

		return;

	}

	int md=(lt+rt)/2;

	build(lt,  md,lch(p));

	build(md+1,rt,rch(p));

	trF[p] = max( trF[lch(p)], trF[rch(p)] );

	if(trL[ lch(p) ] == (md+1-lt))

	{

		trL[p] = trL[ lch(p) ] + trL[ rch(p) ]*(dat[md]==dat[md+1]);

	}

	else 

	{

		trL[p] = trL[ lch(p) ];

	}

	if(trR[ rch(p) ] == (rt-md))

	{

		trR[p] = trR[ rch(p) ] + trR[ lch(p) ]*(dat[md]==dat[md+1]);

	}

	else 

	{

		trR[p] = trR[ rch(p) ];

	}

	trF[p] = max(trF[p], trL[p]);

	trF[p] = max(trF[p], trR[p]);

	if(dat[md]==dat[md+1]) trF[p] = max(trF[p], trR[lch(p)]+trL[rch(p)]);

}





int query(int lt,int rt,int p,int s,int t)

{

	//cout<<lt<<" "<<rt<<" "<<p<<trL[p]<<" "<<trR[p]<<" "<<trF[p]<<endl;

	if(s==lt && t==rt)

	{
		//cout<<"Equal range: "<<trF[p]<<"\n";

		return trF[p];

	}

	int md=(lt+rt)/2;

	if(t<=md) return query(lt,md,lch(p),s,t);

	if(s>md)  return query(md+1,rt,rch(p),s,t);

	int ret = max( query(lt,md,lch(p),s,md), query(md+1,rt,rch(p),md+1,t) );

	//cout<<"max: "<<ret<<" "<<trR[lch(p)]+trL[rch(p)]<<"\n";

	return max(ret, min(trR[lch(p)],md+1-s) + min(trL[rch(p)], t-md));

}



int main()

{

	#define ni(x) (scanf("%d",&x))

	while(1)
	{

		ni(n);
		if(!n)break;

		ni(q);

		for(int i=1;i<=n;i++)

			ni(dat[i]);

		build(1,n,1);

		//show(trL+1,trL+41);

		//show(trR+1,trR+41);

		//show(trF+1,trF+41);

	

		while(q--)

		{

			int s,t;

			ni(s);

			ni(t);

			cout<<query(1,n,1,s,t)<<endl;

		}
	}

}


