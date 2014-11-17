int f;
char s[100];
main()
{
	while(gets(s))
	{
        int i=0;
		do {
            if(s[i]=='"')
            {
            if(f==0)
            printf("``");
            else
            printf("''");
            f=!f;
            }
            else
                putchar(s[i]); 
            i++;
        }while( s[i]!='\0' );
        putchar(10);
	}
}

