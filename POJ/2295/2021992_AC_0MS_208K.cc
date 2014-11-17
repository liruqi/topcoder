#include <iostream>
using namespace std;

char str[261];
int readNum(int s, int e){
	int length=e-s+1;
	int r=1;
	if(e>=s) r=str[e]-'0';
	if(e-1>=s) r+=(str[e-1]-'0')*10;
	if(e-2>=s) r+=(str[e-2]-'0')*100;
	if(e-3>=s) r+=(str[e-3]-'0')*1000;
	return r;
}

int main()
{
 	int start,end;
 	int xcoef,ccoef;
 	int i,t;cin>>t;
	while(t--){
		cin>>str;
		xcoef=0; ccoef=0;i=0;
		while(str[i]!='='){
			start=i;
			for(i++; str[i]!='+'&&str[i]!='-'&&str[i]!='=';i++);
			end=i-1;
			if(str[end]=='x'){
				if(str[start]=='-')
					xcoef-=readNum(start+1, end-1);
				else if(str[start]=='+')
				    xcoef+=readNum(start+1, end-1);
    			else 
    				xcoef+=readNum(start, end-1); 
			}
			else{
				if(str[start]=='-')
					ccoef-=readNum(start+1, end);
				else if(str[start]=='+')
				    ccoef+=readNum(start+1, end);
    			else
    				ccoef+=readNum(start, end);
			}
		}
		i++;
		while(str[i]!='\0'){
			start=i;
			for(i++; str[i]!='+'&&str[i]!='-'&&str[i]!='\0';i++);
			end=i-1;
			if(str[end]=='x'){
				if(str[start]=='-')
					xcoef+=readNum(start+1, end-1);
				else if(str[start]=='+')
				    xcoef-=readNum(start+1, end-1);
    			else 
    				xcoef-=readNum(start, end-1); 
			}
			else{
				if(str[start]=='-')
					ccoef+=readNum(start+1, end);
				else if(str[start]=='+')
				    ccoef-=readNum(start+1, end);
    			else
    				ccoef-=readNum(start, end);
			}
		}
//		cout<<"xcoef "<<xcoef<<endl
//			<<"ccoef "<<ccoef<<endl	;
		if(xcoef==0){
			if(ccoef)
		        cout<<"IMPOSSIBLE"<<endl;
		    else
				cout<<"IDENTITY"<<endl;
		}
		else{
			ccoef*=-1;
			i=ccoef/xcoef;
			if(i<=0 && (ccoef%xcoef))
				i--;
			cout<<i<<endl;	
		}
	}
//	system("pause");
	return 0;
}
