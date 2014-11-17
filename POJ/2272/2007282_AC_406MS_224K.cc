#include <iostream>
#include <math.h>
using namespace std;
double c[12],s1,s2,dis;

int main()
{
 	int i;
 	int d;
 	for(i=0; i<12; i++) cin>>c[i];
 	while(c[0]!=-100){
		s1=0;s2=0;
		for(i=0; i<3; i++){
			dis=sqrt(c[2*i]*c[2*i] + c[2*i+1]*c[2*i+1]);
			d=(int)dis;
			if(d==dis && d>0) d-=3;
			d/=3;
			if(5>d)
				s1 += (5-d)*20;
		}
		for(i=3; i<6; i++){
			dis=sqrt(c[2*i]*c[2*i] + c[2*i+1]*c[2*i+1]);
			d=(int)dis;
			if(d==dis && d>0) d-=3;
			d/=3;
			if(5>d)
				s2 += (5-d)*20;
		}
		cout<<"SCORE: "
			<<s1
			<<" to "
			<<s2
			<<", ";
		if(s1>s2)
			cout<<"PLAYER 1 WINS."
				<<endl;
		else if(s1<s2)
		    cout<<"PLAYER 2 WINS."
				<<endl;
		else 
			cout<<"TIE."
				<<endl;
		for(i=0; i<12; i++) cin>>c[i];
	}
	return 0;			
}
