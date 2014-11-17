#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10000
#define M 27

char s[N][M],word[M];

int replace(char *s,char *w) {
	int lens=strlen(s),lenw=strlen(w),i,p;
	if (lens==lenw) {
		p=0;
		for (i=0;i<lens;++i)
			if (s[i]!=w[i]) {
				if (p) return 0;
				p=1;
			}
		return 1;
	}
	if (lens+1==lenw) {
		i=0;
		while ((i<lens) && (s[i]==w[i])) ++i;
		for (++i;i<lenw;++i)
			if (s[i-1]!=w[i]) return 0;
		return 1;
	}
	if (lens==lenw+1) {
		i=0;
		while ((i<lenw) && (s[i]==w[i])) ++i;
		for (++i;i<lens;++i)
			if (s[i]!=w[i-1]) return 0;
		return 1;
	}
	return 0;
}

main() {
	int n,i;
	for (n=0;;++n) {
		scanf("%s",s[n]);
		if (s[n][0]=='#') break;
	}

	while (scanf("%s",word) && word[0]!='#') {
		for (i=0;i<n;++i)
			if (!strcmp(s[i],word)) break;
		if (i<n) {
			printf("%s is correct\n",word);
		}
		else {
			printf("%s:",word);
			for (i=0;i<n;++i)
				if (replace(s[i],word)) printf(" %s",s[i]);
			printf("\n");
		}
	}
}
