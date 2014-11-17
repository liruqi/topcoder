#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char buf[1000];
    int end;
    do{
        end=0;
        gets(buf);
        if(!strcmp(buf, "EOF")) break;
        int len=strlen(buf);
        for(int i=0;i+2<=len;){
            if(string(buf+i,buf+i+2)=="dd")
            {
                buf[i]='p';
                buf[i+1]='*';
                i+=2;
                continue;
            }
            else if((!i||buf[i-1]!='c') && string(buf+i,buf+i+2)=="ei"){
                buf[i]='i';
                buf[i+1]='e';
                i+=2;
                continue;
            }
            if(i+4<=len && string(buf+i,buf+i+4)=="pink"){
                memmove(buf+i+1, buf+i, len-i+1);
                memcpy(buf+i, "floyd", 5);
                len++;
                i+=5;
                continue;
            }
            i++;
        }
        for(int i=0;i<len;i++)
            if(islower(buf[i]) || buf[i]==' ')
            putchar(buf[i]);
            else if(i+3<=len && string(buf+i,buf+i+3)=="EOF"){
                end=1;
                break;
            }
        puts("");
    }while(!end);
}
