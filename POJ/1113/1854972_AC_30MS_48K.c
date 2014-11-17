#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 1001
#define PI 3.14159265
typedef struct point{
	int x,y;
}point;

point a[N];//a[]为输入
int s[N],top;
int n,l;

int cross(point p0,point p1,point p2)//差积(p0,p1)X(p0,p2)
{
	int     x1=p1.x-p0.x,
		y1=p1.y-p0.y,
		x2=p2.x-p0.x,
		y2=p2.y-p0.y;
	return (x1*y2-x2*y1);
}

double distance(point p1,point p2)
{
    return sqrt((double) ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)) );
}

int get_min()
{
	int i,index;
	index=1;
	for(i=2;i<=n;i++)
		if(a[i].x<a[index].x || a[i].x==a[index].x&&a[i].y<a[index].y)
			index=i;
	return index;
}

void get_c()
{
	int temp,t,pp,i;
	s[0]=get_min();
	top=0;
	pp=s[top];
	do{
		t=pp+1;
		if(t>n)
			t=t-n+1; //???
		for(i=1;i<=n;i++)
			if(i!=pp)
				if( (temp=cross(a[pp],a[t],a[i]))>0 || 
					temp==0 && distance(a[pp],a[i])>distance(a[pp],a[t]) )
					t=i;
		s[++top]=t,pp=s[top];
	}while(pp!=s[0]);
}

int main()
{
    int i;
    double sum;
    while(scanf("%d%d",&n,&l)==2){
        sum=0;
        for(i=1;i<=n;i++)
            scanf("%lld%lld",&a[i].x,&a[i].y);
		get_c();
		for(i=0;i<top;i++)
			sum+=distance(a[s[i]],a[s[i+1]]);
        sum+=2*PI*l;
        printf("%.0f\n",sum);
    }
    return 0;
}



