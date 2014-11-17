
#include <iostream>
using namespace std;
int month[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,
                  31,29,31,30,31,30,31,31,30,31,30,31};
const char xq[7][15]={"sunday", "monday", "tuesday", 
"wednesday","thursday","friday","saturday"};
bool isleap(const int &year)
{
    if(year%4==0 && year%100!=0) return true;
    if(year%400==0) return true;
    return false;    
}
int main()
{
    int day;
    int y, m, dt, dd; // year, month, date, day
    while(cin>>y>>m>>dt)
    {
        int i, leap;
        day=0;
        for(i=1; i<y; i++)
            if(isleap(i)) day+=366;
            else day+=365;
        
        leap=isleap(y);
        for(i=1; i<m; i++)
            day+=month[leap][i-1];
        day+=dt;
        dd=day%7;
        cout<<xq[dd]<<endl; 
    }
    return 0;
}