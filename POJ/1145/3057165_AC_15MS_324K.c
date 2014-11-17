

#define mx 10000



char sexp[mx], buf[mx];

int n,top,lb,rb;



void add(){

	int i,bl = strlen(buf);

	for(i=0;i<bl;i++)

	if(buf[i]!=' '){

		char c=buf[i];

		sexp[top++]=c;

		if(c=='(')lb++;

		if(c==')')rb++;

	}

}



int tree(){

	return lb==rb;

}



int val[mx];

int idx[mx];

int dp[mx];

int cc[mx];

int pair[mx];

int sp;



int s2i(int left,int right){

    int len = right-left, ret;

    memcpy(buf, sexp+left, len);

    buf[len]=0;

    sscanf(buf, "%d", &ret);

    return ret;

}



int mktree(int left, int right, int father){

    left++;

    right--;

    if(left>right)return 0;

    int i=left;

    while(isdigit(sexp[i])||sexp[i]=='-') i++;//sexp[i] = '('

    int ci=sp++;

    val[ci]=s2i(left,i);

    idx[ci]=father;

    cc[ci]+=mktree(i, pair[i],ci);

    i=pair[i]+1;

    cc[ci]+=mktree(i, pair[i],ci);
	return 1;

}



void mkidx(){

    int i;

    int stk[mx/100],st=0;

    for(i=0;i<top;i++)

        if(sexp[i]=='(')

            stk[st++]=i;

        else if(sexp[i]==')')

            pair[stk[--st]]=i;

	sp=0;

	mktree(0,pair[0],-1);

}



int solve(){

    dp[0]=val[0];

    int i;

    for(i=1;i<sp;i++)dp[i]=dp[idx[i]]+val[i];

    for(i=0;i<sp;i++)if(!cc[i] && dp[i]==n)return 1;

    return 0;

}



int main(){

	while(scanf("%d",&n) != -1){

		lb=rb=top=0;

		memset(cc,0,sizeof(cc));

		memset(pair,0,sizeof(pair));

		while(1){

    		gets(buf);

    		add(buf);

    		if(tree())break;

		}

		//sexp[top]=0;

		//puts(sexp);

		mkidx();

		puts(solve()?"yes":"no");

	}

}

//-5 (-5()())