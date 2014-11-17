#include <stdio.h>
#include <ctype.h>
#include <string.h>
char ms1[10], ms2[10];
int n1, n2;
int m2d(char *ms, int length)
{
	int i,n=0;
	for(i=0; i<length; i++)
	{
		switch(ms[i])
		{
		case 'm':
			if(i>0 && isdigit(ms[i-1]))
				n+=1000*(ms[i-1]-'0');
			else
				n+=1000;
			break;
		case 'c':
			if(i>0 && isdigit(ms[i-1]))
				n+=100*(ms[i-1]-'0');
			else 
				n+=100;
			break;
		case 'x':
			if(i>0 && isdigit(ms[i-1]))
				n+=10*(ms[i-1]-'0');
			else 
				n+=10;
			break;
		case 'i':
			if(i>0 && isdigit(ms[i-1]))
				n+=(ms[i-1]-'0');
			else
				n++;
			break;
		default:
			break;
		}
	}
	return n;
}

void d2m(int n)
{
	if(n/1000)
	{
		if(n/1000 > 1) printf("%d", n/1000);
		putchar('m');
	}
	n=n%1000;
	if(n/100)
	{
		if(n/100 > 1) printf("%d", n/100);
		putchar('c');
	}
	n=n%100;
	if(n/10)
	{
		if(n/10 > 1) printf("%d", n/10);
		putchar('x');
	}
	n=n%10;
	if(n)
	{
		if(n > 1) printf("%d", n);
		putchar('i');
	}
	putchar(10);
}

int main()
{
int tc; scanf("%d", &tc);
while(tc--){
scanf("%s%s",ms1, ms2);
n1 = m2d(ms1, strlen(ms1));
n2 = m2d(ms2, strlen(ms2));
d2m(n1+n2);
}
return 0;
}