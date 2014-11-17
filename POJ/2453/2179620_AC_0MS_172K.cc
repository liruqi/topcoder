#include <iostream.h>
int lowBit(int n){ return n&-n; }
int main()
{
    int I, no1,i;
    while( cin>>I && I)
    {
        no1=0;
        for(i=(lowBit(I)<<1);i & I; i <<= 1) no1++;
        cout<<(I + lowBit(I) + (1<<no1) -1)<<endl;
    }
}
