int row,col;
char map[11][11];

int sr[110],sc[110],top;
int horizontal(){
    int i,j;
    top=0;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++){
            char c=map[i][j];
            if(c!='.'){
                if(c=='-') 
                    sr[top]=i,sc[top]=j,top++;
                else 
                    return 0;
            }
        }
    for(i=1;i<top;i++)
        if(sr[i]!=sr[i-1] || sc[i]!=sc[i-1]+1)
            return 0;
    return top>0;
}

int vertical(){
    int i,j;
    top=0;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++){
            char c=map[i][j];
            if(c!='.'){
                if(c=='|') 
                    sr[top]=i,sc[top]=j,top++;
                else 
                    return 0;
            }
        }
    for(i=1;i<top;i++)
        if(sr[i]!=sr[i-1]+1 || sc[i]!=sc[i-1])
            return 0;
    return top>0;
}

int diagonal1(){
    int i,j;
    top=0;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++){
            char c=map[i][j];
            if(c!='.'){
                if(c=='\\') 
                    sr[top]=i,sc[top]=j,top++;
                else 
                    return 0;
            }
        }
    for(i=1;i<top;i++)
        if(sr[i]!=sr[i-1]+1 || sc[i]!=sc[i-1]+1)
            return 0;
    return top>0;
}

int diagonal2(){
    int i,j;
    top=0;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++){
            char c=map[i][j];
            if(c!='.'){
                if(c=='/') 
                    sr[top]=i,sc[top]=j,top++;
                else 
                    return 0;
            }
        }
    for(i=1;i<top;i++)
        if(sr[i]!=sr[i-1]+1 || sc[i]!=sc[i-1]-1)
            return 0;
    return top>0;
}

int right(){
    scanf("%d",&row);
    scanf("%d",&col);
    int i;
    for(i=0;i<row;i++)
        scanf("%s", map[i]);
    return horizontal()||vertical()||diagonal1()||diagonal2();
}

int main(){
    int ks; scanf("%d",&ks);
    while(ks--) 
        puts(right()?"CORRECT":"INCORRECT");
}
