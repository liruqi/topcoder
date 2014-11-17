
int n,i,mary,last,top;
void slv(){
	scanf("%d",&n);
	top=1;
	scanf("%d",&last);
	for(i=1;i<n;i++){
		scanf("%d",&mary);
		if(top%2){
			if(mary < last)
				top++;
		} else {
			if(mary > last)
				top++;
		}
		last=mary;
	}
	printf("%d\n",top);
}

int main()
{
	int ks; 
	scanf("%d",&ks);
	while(ks--) 
		slv();
}
