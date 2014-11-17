#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string kw, ct;
	char pt[110];
	int i,j;
	while(cin>>kw && kw!="THEEND"){
		cin>>ct;
		vector <int> order;
		for(char c='A'; c<='z'; c++){
			for(i=0;i<kw.size();i++)
				if(kw[i]==c)
					order.push_back(i);
		}

		int col=ct.size()/order.size();
        for(i=0;i<order.size();i++){
            for(j=0;j<col;j++)
                pt[j*order.size()+order[i]]=ct[i*col+j];
        }
		for(i=0;i<ct.size();i++) cout<<pt[i];
		cout<<endl;
	}
}
/*
BATBOY
EYDEMBLRTHANMEKTETOEEOTH
HUMDING
EIAAHEBXOIFWEHRXONNAALRSUMNREDEXCTLFTVEXPEDARTAXNAARYIEX
THEEND
*/
