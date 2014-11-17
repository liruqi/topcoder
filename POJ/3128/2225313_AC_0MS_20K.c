#include <stdio.h>
#include <string.h>

int F[27];
char G[27];
int A[27];
int C[27];

void init()
{
	int i=0;
    for(; i<26; i++)
	{
	    A[i] = G[i]-'A';
		F[i] = 1;
        C[i] = 0;
	}
}

int yes(){
    int i;
    for(i=0; i<26; i++) if(F[i])
    {
        int cnt=1;
        int j=A[i];
		F[i]=0;
		while(j!=i){
			F[j]=0;
            j=A[j];
            cnt++;
        }
        C[cnt]++;
    }
    for(i=2; i<27; i+=2) if(C[i])
    {
        if(C[i]%2)
            return 0;
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",G);
        init();
        if(yes()) 
            puts("Yes");
		else 
            puts("No");
    }
    return 0;
}
