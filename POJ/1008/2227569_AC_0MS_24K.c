#include<stdio.h>
#include<string.h>    
const char Ha[][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", 
               "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", 
               "muan", "pax", "koyab", "cumhu","uayet"};
const char Tz[][10]={"imix", "ik", "akbal", "kan", "chicchan", 
               "cimi", "manik", "lamat", "muluk", "ok", "chuen", 
               "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac","ahau"};

main(){
	int yr,dy,td,di,i;
	char c, ms[10];
	int T;
	scanf("%d",&T);
	printf("%d\n",T);
	while(T--){
		scanf("%d%c%s%d", &dy, &c, ms, &yr);
		td=yr*365;
		for(i=0; i<18 && strcmp(ms, Ha[i]); i++)
			td+=20;
		td+=dy;
		yr=td/260;
		dy=td%13;
		printf("%d %s %d\n", dy+1, Tz[td%20], yr);	
	}
	return 0;
}

