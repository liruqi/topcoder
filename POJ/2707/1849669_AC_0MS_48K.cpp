#include <iostream.h>

int a,b,c,d;
double t[4];
double r[2];
int main()
{
	while( cin>>a>>b>>c>>d && c&&d)
	{
		t[0]=(double)c/a;
		t[1]=(double)d/b;
		t[2]=(double)d/a;
		t[3]=(double)c/b;

	r[0]=t[0]<t[1]?t[0]:t[1];
	r[1]=t[2]<t[3]?t[2]:t[3];

	r[0]=r[0]>r[1]?r[0]:r[1];
	a= r[0]*100;
	a=(a>100)?100:a;
	a=(a<1)?1:a;
	cout<<a
		<<"%"
		<<endl;
	}
	return 0;
}