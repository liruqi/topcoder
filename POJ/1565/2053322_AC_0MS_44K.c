#include<stdio.h>
#include<string.h>
int main()
{       int i,j; __int64 sum;
	char str[50];
	gets(str);
	while(str[0]!='0'){
		sum=0;
		for(i=strlen(str)-1, j=0; i>=0; i--,j++){
			sum+=((2<<j) - 1)*(str[i]-'0');
		}
		printf("%I64d\n", sum);
		gets(str);
	}
	return 0;
}
