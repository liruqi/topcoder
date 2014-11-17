int ks,odd,even,s,c[50],i;
int solve(){
	if(s&1) return 1;
	odd=even=0;
	for(i=0;i<s;i++)
		if(c[i]){
			if(i&1) odd++;
			else even++;
		}
	if(abs(odd-even)<2)
		return 1;
	return 0;
}

int main(){
	scanf("%d",&ks);
	while(ks--){
		scanf("%d",&s);
		for(i=0;i<s;i++){
			scanf("%d",c+i);
		}
		puts(solve()?"YES":"NO");
	}
}
