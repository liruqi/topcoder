#include<iostream.h>
#include<string.h>
#include<stdio.h>
char inver(char);
int main()
{
	char array[100];
	while(gets(array))
	{
		if(strcmp("START",array)==0||strcmp(array,"END")==0) continue;
		else if(strcmp(array,"ENDOFINPUT")==0) break;
	    else{
				for(int i=0;i<strlen(array);i++)
				{
					array[i]=inver(array[i]);
				}
				cout<<array<<endl;
			}
	}
	 

	return 0;
}

char inver(char c)
{
	if(c=='A')return 'V';
	if(c=='B')return 'W';
	if(c=='C')return 'X';
	if(c=='D')return 'Y';
	if(c=='E')return 'Z';
	if(c=='F')return 'A';
	if(c=='G')return 'B';
	if(c=='H')return 'C';
	if(c=='I')return 'D';
	if(c=='J')return 'E';
	if(c=='K')return 'F';
	if(c=='L')return 'G';
	if(c=='M')return 'H';
	if(c=='N')return 'I';
	if(c=='O')return 'J';
	if(c=='P')return 'K';
	if(c=='Q')return 'L';
	if(c=='R')return 'M';
	if(c=='S')return 'N';
	if(c=='T')return 'O';
	if(c=='U')return 'P';
	if(c=='V')return 'Q';
	if(c=='W')return 'R';
	if(c=='X')return 'S';
	if(c=='Y')return 'T';
	if(c=='Z')return 'U';

}
