#include <iostream>
using namespace std;


int A[5];
struct DNA{
    char S[51];
    int O;
}D[100];

int id(char c){
    switch(c){
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return 0;
    } 
}
int cmp(const void *a, const void *b){
    struct DNA *aa=(struct DNA *)a;
    struct DNA *bb=(struct DNA *)b;
    return aa->O-bb->O;
}

int main()
{
    int n,m,row,col,i,j;
    cin>>m>>n;
    for(row=0; row<n; row++){
        memset(A, 0, sizeof(A));
        int cnt=0;
        cin>>D[row].S;
        for(col=0; col<m; col++)
        {
            int num=id((D[row].S)[col]);
            A[num]++;
            for(num++; num<=4; num++)
            cnt+=A[num];
        }
        D[row].O=cnt;
    }
    qsort(D, n, sizeof(D[0]), cmp);
    for(i=0; i<n; i++)
    {
        puts(D[i].S);
    }
    cin>>m;
}
