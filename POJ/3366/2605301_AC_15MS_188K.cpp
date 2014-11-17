#include <string>
#include <iostream>
#include <map>
using namespace std;
const char vowel[10]="aeiou";

bool confy(string &org){
    int lp=org.size()-1;
    if(org[lp]!='y')return 0;
    lp--;
    if(lp<0) return 0;
    for(int i=0;i<5;i++)
        if(vowel[i]==org[lp])
            return 0;
    return 1;
}

bool endins(string &org){
    int lp=org.size()-1;
    char lt1=org[lp];
    if(lt1=='o'||lt1=='s'||lt1=='x')
        return 1;
    if(lt1=='h' && lp>0){
        if(org[lp-1]=='c'||org[lp-1]=='s')
            return 1;
    }
    return 0;
}

int main(){
    int N,L,i;
    cin>>N>>L;
    map<string, string>irr;
    string org, plu;
    for(i=0;i<N;i++){
        cin>>org>>plu;
        irr[org]=plu;
    }
    for(i=0;i<L;i++){
        cin>>org;
        if(irr[org] != "")
            cout<<irr[org];
        else if(confy(org)){
            string dy(&org[0], &org[org.size()-1]);
            cout<<(dy+"ies");
        }
        else if(endins(org)){
            cout<<(org+"es");
        }
        else {
            cout<<(org+"s");
        }
        cout<<endl;
    }
    return 0;
}
