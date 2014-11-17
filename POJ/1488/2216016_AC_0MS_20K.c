int f;
char s[100];
void ptq()
{
    if(f==0)
        printf("``");
    else
        printf("''");
    f=!f;
}

main()
{
	
	while(gets(s))
	{
        int i=0;
		do {
            if(s[i]=='"')
                ptq();
            else
                putchar(s[i]); 
            i++;
        }while( s[i]!='\0' );
        putchar(10);
	}
}

