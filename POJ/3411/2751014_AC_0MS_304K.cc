#include <iostream>
using namespace std;

int ans;

int a[11],b[11],c[11],p[11],r[11],last[11];

int n,m;

int const inf = 1000000000;

void DFS(int now,int state,int mon)
{
    int i,j;

    if (now==n && mon<ans) ans=mon;

    int sta=state;

    for (i=0;i<m;i++)

        if (c[i]==now)

            state=state | (1<<i);

    for (i=1;i<=n;i++)

        if (last[i]!=state || last[i]==-1)
        {

            int mm=inf;

            for (j=0;j<m;j++)
                if (a[j]==now && b[j]==i)

                  if ( (1<<j) & state )
                  {
                      if (p[j]<mm) mm=p[j];
                  }
                  else
                  {
                       if (r[j]<mm) mm=r[j];
                  }

           if (mm==inf) continue;

           int ori=last[i];

           last[i]=state;

           DFS(i,state,mon+mm);

           last[i]=ori;

        }

    state=sta;
}

int main()
{
    while (cin>>n>>m)
    {
        int i;
        for (i=0;i<m;i++)
            cin>>a[i]>>b[i]>>c[i]>>p[i]>>r[i];
        ans=inf;
        memset(last,-1,sizeof(last));

        last[1]=0;

        DFS(1,0,0);

        if (ans==inf) cout<<"impossible"<<endl;
        else

        cout<<ans<<endl;
    }
    return 0;
}