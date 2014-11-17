#include <stdio.h>
#include <string.h>
void main()
{
	char input[10000];
	int i,sum;
	scanf("%s",input);
	while(strcmp(input,"0")!=0){
		sum=0;
		for(i=0;input[i]!='\0';i++){
			sum=(sum+(input[i]-'0'+0))%9;
		}
		if(sum==0) printf("9\n");
		else printf("%d\n",sum);
		scanf("%s",input);
	}
}