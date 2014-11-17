char buf[50];
char num[4][9];
int len[4],ll,top;

int main(){
    int nt=1;
	while(nt){
		memset(num,'0',sizeof(num));
		memset(len,0,sizeof(len));
		gets(buf);
        nt=strcmp(buf,"0+0=0");
		ll=strlen(buf);
		top=0;
		int i;
		for(i=0;i<ll;i++){
			if(isdigit(buf[i])) num[top][len[top]++]=buf[i];
			else top++;
		}
		/*puts(num[0]);
		puts(num[1]);
		puts(num[2]);
		*/
        int carry=0;
        for(i=0;i<9;i++){
            char now=num[0][i]+num[1][i]+carry-'0';
            if(now>'9'){
                carry=1;
                now-=10;
            } else {
                carry=0;
            }
            num[3][i]=now;
        }
        puts(memcmp(num[2],num[3],9)?"False":"True");
	}
}
