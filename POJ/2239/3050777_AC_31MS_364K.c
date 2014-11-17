int N;
int mat[100],vst[100];
int adj[310][100];
int dgr[310];

int dfs(int p){
int t,j;
for(j=0;j<84;j++)
if(!vst[j]&&adj[p][j]){
vst[j]=1;
t=mat[j];
if(t==-1||dfs(t)){mat[j]=p;return 1;}
}
return 0;
}

void slv(){
int i,cnt=0;
memset(mat,-1,sizeof(mat));
for(i=0;i<N;i++){
memset(vst,0,sizeof(vst));
if(dfs(i))cnt++;
}
printf("%d\n",cnt);
}

int main(){
int i,j,p,q;
while(~scanf("%d",&N)){
memset(adj,0,sizeof(adj));
for(i=0;i<N;i++){
scanf("%d",dgr+i);
for(j=dgr[i];j;j--)scanf("%d%d",&p,&q),adj[i][(p-1)*12+q-1]=1;
}//for
slv();
}//while
}
