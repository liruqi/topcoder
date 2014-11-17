#include <iostream>
using namespace std;
const int expv=6174;

int A[10];

bool valid(int n){
    if(n>9999||n<1000) return 0;
    while(n){
        A[n%10]++;
        n/=10;
    }
    for(int i=0;i<10;i++) if(A[i]) n++;
    return n>1;
}

int bn(int n){
    memset(A,0,40);
    while(n){
        A[n%10]++;
        n/=10;
    }
    int i,j=1,ans=0;
    for(i=0;i<10;i++)
    {
        while(A[i]){
            ans+=i*j;
            j*=10;
            A[i]--;
        }
    }
    return ans;
}
int sn(int n){
    memset(A,0,40);
    while(n){
        A[n%10]++;
        n/=10;
    }
    int i,j=1,ans=0;
    for(i=9;i>=0;i--)
    {
        while(A[i]){
            ans+=i*j;
            j*=10;
            A[i]--;
        }
    }
    return ans;
}

int main()
{
    int n,cnt,sl,bg;
    /*
    while(cin>>n){
        cout<<bn(n)<<' '
            <<sn(n)<<endl;
    }*/
    while(cin>>n&&n>=0){
        cout<<"N="<<n<<':'<<endl;
        if(!valid(n)) puts("No!!");
        else {
            cnt=0;
            while(n && n!=expv){
                sl=sn(n);
                bg=bn(n);
                cout<<bg<<'-'<<sl<<'='<<bg-sl<<endl;
                cnt++;
                n=bg-sl;
            }
            cout<<"Ok!! "<<cnt<<" times\n";
        }
    }
}
