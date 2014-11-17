#include <iostream.h>

int F[26], n;
char G[60];

int main()
{
    while(cin>>n && n){
        int cnt=0, gone = 0, i, j;
        for(i=0; i<26; i++)
            F[i]=0;
        cin>>G;
        for(i=0; G[i]!='\0'; i++)
        {
            j = G[i]-'A';
            if(F[j]) {
                F[j]=false;
                cnt--;
            }
            else {
                if(cnt>=n) 
                    gone++;
                F[j]=true;
                cnt++;
            }
        }
        if(gone)
            cout<<gone<<" customer(s) walked away."<<endl;
        else 
            cout<<"All customers tanned successfully."<<endl;
    }
    return 0;
}
