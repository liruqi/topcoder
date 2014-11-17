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
        for(i=(lowBit(I)<<1); i<=I; i <<= 1)
        {
            if(i & I)
                no1++;
            else 
                break;    
        }
        J = I + lowBit(I);
        for(i=0; i<no1; i++)
        {
           J += (1<<i);
        }
        cout<<J<<endl;
    }
    return 0;
}

