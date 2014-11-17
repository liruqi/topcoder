#include <iostream>
using namespace std;
struct point{
int x, y;
}P[201];
bool line(int p1, int p2, int px)
{
int vbx=P[p1].x-P[p2].x;
int vby=P[p1].y-P[p2].y;
int vx=P[p1].x-P[px].x;
int vy=P[p1].y-P[px].y;
return (vbx*vy==vby*vx);
}
int N;
int main()
{
int i, j, k, max=2; cin>>N;
for(i=1; i<=N; i++) 
cin>>P[i].x>>P[i].y;
for(i=1; i<N-1; i++) for(j=i+1; j<N; j++){
int cnt=2;
for(k=j+1; k<=N; k++) if( line(i, j, k) ) cnt++;
if(cnt>max) max=cnt;
}
cout<<max<<endl;
return 0;
}
