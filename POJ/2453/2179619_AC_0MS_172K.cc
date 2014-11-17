#include <iostream>
using namespace std;

int lowBit(int n){ 
    return n&-n; 
}

int main()
{
    int I, J, no1;
    int i;
    while( cin>>I && I)
    {
        no1=0;
        for(i=(lowBit(I)<<1);i & I; i <<= 1)
                no1++;
        J = I + lowBit(I) + (1<<no1) -1;
        cout<<J<<endl;
    }
    return 0;
}
