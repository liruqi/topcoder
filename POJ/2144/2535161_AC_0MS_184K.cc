#include <stdio.h>
int Ni[8], key, N9;

int main(){
	int S; scanf("%d",&S);
	while(S--){
		int i,carry=0;
		key=0;
		for(i=0;i<8;i++) {
			scanf("%x",&Ni[i]);
		}
		scanf("%x",&N9);
		for(int bit=0;bit<32;bit++){
int i, bitsum=0;
	for(i=0;i<8;i++)
		if(Ni[i]&(1<<bit))
			bitsum++;
	int bv=(bitsum+carry)&1;
	if((bv<<bit) - (N9&(1<<bit))){
		key = key|(1<<bit);
		carry=(carry + 8-bitsum)/2;
	}
	else {
		key = key&(~(1<<bit));
		carry=(carry+ bitsum)/2;
	}

}
		printf("%x\n",key);
	}
	return 0;
}