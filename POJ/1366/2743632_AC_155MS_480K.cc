#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

char tab[2][2][2];
int n;
void convert(string &m){
    string s(m);
    int  a, b, c;
    for(int i=0; i<n; i++){
        a=(i+n-2)%n;
        c=(i+1)%n;
        a=s[a]-'a';
        b=s[i]-'a';
        c=s[c]-'a';
        m[i]=tab[a][b][c];
    }
}

void lexmin(string &m){
    string s(m);
    for(int i=1;i<n;i++){
        rotate(s.begin(), s.begin()+1, s.end());
        if(m>s) m=s;
    }
}

int main()
{
    int i, s, top, a, b, c;
    string org, mes, conv;
    while( cin>>n>>org) {
	    for(i=0;i<8;i++)
	    {
	        cin>>conv;
	        a=conv[0]-'a';
	        b=conv[1]-'a';
	        c=conv[2]-'a';
	        tab[a][b][c]=conv[3];
	    }
	    cin>>s;
	    
	    map<string, int> ms;
	    mes = org;
	    for(i=1;ms.find(mes)==ms.end();i++){
	        ms.insert(make_pair(mes,i));
	        convert(mes);
	    }
	    top=i;
	    int p=top-ms[mes];
	    int sl=ms[mes];
	    if(s>=top)
	        s-=sl, s%=p, s+=sl;
		//cout<<sl<<' '<<p<<' '<<top<<endl;
	    for(mes=org, i=1;i<=s;i++)
	        convert(mes);
	    //cout<<mes<<endl;
	    lexmin(mes);
	    cout<<mes<<endl;
    }
    return 0;
}
/*
5
abaaa
aaa1
aab2
aba3
abb4
baa5
bab6
bba7
bbb8
1
*/
