int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	__asm {
		mov eax, a
		add eax, b
		mov a, eax
	}
	printf("%d",a);
	return 0;
}
