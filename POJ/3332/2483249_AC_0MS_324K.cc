#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char rn[1100];
int T, sl;

bool real(){
    int i;
    int dp=-1,ep=-1,sp=-1;
    for(i=0;i<sl;i++) {
        if(!isdigit(rn[i])){
            switch(tolower(rn[i])){
                case '.':
                    if(i==0 || i==sl-1 || dp>0) return 0;
                    dp=i;
                    break;
                case 'e':
                    if(i==0 || i==sl-1 || ep>0) return 0;
                    ep=i;
                    break;
                case '+':
                    if(i==0 || i==sl-1 || sp>0) return 0;
                    sp=i;
                    break;
                case '-':
                    if(i==0 || i==sl-1 || sp>0) return 0;
                    sp=i;
                    break;
                default :
                    return 0;
            }
        }
    }
    if(dp>0){
        if(ep>0){
            if(dp>=ep-1) return 0;
        }
        else if(sp>=0) return 0;
    }
    if(ep>0){
        if(sp>0){
            if(sp!=ep+1)
                return 0;
        }
    }
    else if(sp>0) return 0;
    return 1;
    
}
int main(){
    cin>>T;
    while(T-- && cin>>rn){
        sl=strlen(rn);
        cout<<(real()?"LEGAL":"ILLEGAL")<<endl;
    }
}
