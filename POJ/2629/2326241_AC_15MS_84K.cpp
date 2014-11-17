#include <iostream>
using namespace std;

char a[1010], b[1010];
int c[26], d[26], e[26];

int min(int x, int y){
	return x<y?x:y;
}

int main()
{
	unsigned int i,j;
	while(gets(a)){
		gets(b);
		
		//getchar();
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		memset(e, 0, sizeof(e));
		for(i=0; a[i]!='\0'; i++)
		{
			j=a[i]-'a';
			c[j]++;
		}
		for(i=0; b[i]!='\0'; i++)
		{
			j=b[i]-'a';
			d[j]++;
		}
		for(i=0; i<26; i++){
			e[i]=min(c[i], d[i]);
			while(e[i]--)
				putchar('a'+i);
		}
		putchar(10);
	}
	return 0;
}