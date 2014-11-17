#include<ctype.h>
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

string str;
bool iserr(){
	if(str[0]=='_'||str[str.length()-1]=='_')return 1;
	for(int i=1;i<str.length();i++)if(str[i]=='_'&&str[i-1]=='_')return 1;
	return 0;
}
bool iscpp(){
	for(int i=0;i<str.length();i++)if(isupper(str[i]))return 0;
	return 1;
}
bool isjava(){
	if(isupper(str[0]))return 0;
	for(int i=1;i<str.length();i++)if(str[i]=='_')return 0;
	return 1;
}
void tojava(){
	bool u=0;
	cout<<str[0];
	for(int i=1;i<str.length();i++)
		if(str[i]=='_')u=1;
		else {
			putchar(u?toupper(str[i]):str[i]);
			u=0;
		}
	cout<<endl;
}
void tocpp(){
	for(int i=0;i<str.length();i++)
	if(isupper(str[i])){
		putchar('_');
		putchar(tolower(str[i]));
	}
	else putchar(str[i]);
	cout<<endl;
}
int sol(){
	if(iserr())cout<<"Error!"<<endl;
	else if(iscpp())tojava();
	else if(isjava())tocpp();
	else cout<<"Error!"<<endl;
}
int main(){
	int cpp;
	cin>>str;
	sol();
}
