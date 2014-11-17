#include <stdio.h>
int Ni[8], key, N9;

void findkey(int bit, int carry){
	int i, bitsum=0;
	if(bit>=32) return;
	for(i=0;i<8;i++)
		if(Ni[i]&(1<<bit))
			bitsum++;
	int bv=(bitsum+carry)&1;
	if((bv<<bit) - (N9&(1<<bit))){
		key = key|(1<<bit);
		findkey(bit+1, (carry + 8-bitsum)/2);
	}
	else {
		key = key&(~(1<<bit));
		findkey(bit+1, (carry+ bitsum)/2);
	}
}
int main(){
	int S; scanf("%d",&S);
	while(S--){
		int i;
		key=0;
		for(i=0;i<8;i++) {
			scanf("%x",&Ni[i]);
		}
		scanf("%x",&N9);
		findkey(0, 0);
		printf("%x\n",key);
	}
	return 0;
}