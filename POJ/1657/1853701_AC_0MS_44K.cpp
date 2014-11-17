#include <iostream.h>

inline int absv(int x)
{
	return x<0 ? (-1)*x : x;
}

inline int max(int x,int y)
{
	return x>y?x:y;
}

int x1,x2,y1,y2,n,i;
char c1,c2;
int main()
{
	cin>>n;
	while(n--)
	{
		cin	>>c1
			>>y1
			>>c2
			>>y2;
		x1=c1+1-'a';
		x2=c2+1-'a';
		if(x1==x2 && y1==y2)
		{
			cout<<"0 0 0 0"<<endl;
			continue;
		}
		i=max(absv(x1-x2),absv(y1-y2));	//king
		cout<<i
			<<" ";
		
		if(absv(x1-x2)==absv(y1-y2) || !absv(x1-x2) || !absv(y1-y2))	//queen
			cout<<"1";
		else  
			cout<<"2";
		cout<<' ';

		if(absv(x1-x2) && absv(y1-y2))	//car
			cout<<"2";
		else 
			cout<<"1";
		cout<<" ";

		if(absv(x1+y1-x2-y2)%2)			//elephant
			cout<<"Inf";
		else 
		{
			if(absv(x1-x2)==absv(y1-y2))
				cout<<"1";
			else 
				cout<<"2";
		}
        cout<<endl;
	}
	return 0;
}
