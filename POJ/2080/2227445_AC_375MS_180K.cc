#include <iostream>
using namespace std;
int yr, mh, dy;
static int ms[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char dow[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
bool leap(int k)
{
   if(k%4==0 && k%100!=0 || k%400==0) return true;
   return false;
}

int doy(int y){ 
    return leap(y)?366:365;
}

int dom(int m)
{
	if(leap(yr) && m==2)
		return ms[m]+1;

	return ms[m];
}

int main()
{
    int day;
    while(cin>>day && day>=0){
        int d=day;
        yr=2000;
        mh=1;
        
        while(1){
            int t=doy(yr);
            if(d-t<0)
                break;
            d-=t;
            yr++;
        }
        while(1){
            int t=dom(mh);
            if(d-t<0)
                break;
            d-=t;
            mh++;
        }
        dy=d+1;
        cout<<yr<<'-';
        if(mh<10) putchar('0');
        cout<<mh<<'-';
        if(dy<10) putchar('0');
        cout<<dy<<' ';
        cout<<dow[(day+6)%7]<<endl;
    }
    return 0;
}