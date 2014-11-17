#include<algorithm>
#include<iostream>
using namespace std;
int main(){
int s,m;
while(-1!=scanf("%d%d",&s,&m)) printf("%10d%10d    %s\n\n",s,m,__gcd(s,m)>1?"Bad Choice":"Good Choice");
}