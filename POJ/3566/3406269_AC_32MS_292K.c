
int n;

char get_ch(int x)
{
    if(x<26) return x+'a';
    x-=26;   return x+'A';
}

int main(){
    scanf("%d",&n);
    
    int i,j,k;

    printf("%d %d %d\n",2,n,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            putchar(get_ch(i));
        }puts("");
    }
        puts("");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            putchar(get_ch(j));
        }puts("");
    }
    scanf("%d",&n);
    
}
