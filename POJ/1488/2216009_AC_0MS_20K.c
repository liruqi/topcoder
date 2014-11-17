
#include <stdio.h>

int f;
void ptq()
{
    if(f==0)
    {
        f=1;
        printf("``");
    }
    else
    {
        f=0;
        printf("''");
    }
}

int main()
{
	char s[100];
	f=0;
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
	return 0;		
}

