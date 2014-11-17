#include <iostream>
using namespace std;
#define maxn 100
int que[maxn*maxn], head, tail, dest;

void enque(int n){que[tail++]=n;}
int deque(){return que[head++];}
bool highpri(){
    for(int i=head+1;i<tail;i++) if(que[head]<que[i]) return 0;
    return 1;
}

int main(){
    int T,N,M;
    cin>>T;
    while(T--){
        int cnt=0;
        cin>>N>>M;
        for(int i=0;i<N;i++) cin>>que[i];
        head=0;
        tail=N;
        dest=M;
        while(head<tail){
            if(highpri()){ 
                cnt++;
                if(head==dest) break;
                head++;
            }
            else {
                if(head==dest) 
                    dest=tail;
                enque(deque());
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
