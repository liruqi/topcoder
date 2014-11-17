#include<iostream.h>
#include<math.h>
int value(float a,float b);
int main()
{
	float a,b;
	while(1)
	{
		int result[2];
		result[0]=0;result[1]=0; 
		for(int i=0;i<2;i++)
			for(int j=0;j<3;j++)
			{
				cin>>a>>b;
				if(a==-100)	return 0;
				result[i]+=value(a,b);
			}
        if(result[0]==result[1])
			cout<<"SCORE: "<<result[0]<<" to "<<result[1]<<", TIE."<<endl;
			else 
				if(result[0]>result[1])
					cout<<"SCORE: "<<result[0]<<" to "<<result[1]<<", PLAYER 1 WINS."<<endl;
				else
					cout<<"SCORE: "<<result[0]<<" to "<<result[1]<<", PLAYER 2 WINS."<<endl;
         
	}
	return 0;
}

int value(float a,float b)
{
	a=sqrt(a*a+b*b);
	if(a<=3)return 100;
	else
		if(a<=6)return 80;
		else
			if(a<=9)return 60;
			else
				if(a<=12)return 40;
				else
					if(a<=15)return 20;
					else
						return 0;
}