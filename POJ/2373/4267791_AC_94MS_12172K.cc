#include<iostream>

using namespace std;

const int       maxint32 = 0x7fffffff;

int             n, m, a, b;
int             f[1000008], que[1000008], s[1000008], e[1000008];
template<class T>
void show(T x){ cout<< "# "<< x <<endl; }
template<class T>
void show(T b,T e){ cout<<"$ "; for(T i=b;i!=e;i++) cout<<*i<<", ";cout<<endl; }

int             main()
{
    int         i, j, x, y, count;
    while (scanf("%d%d", &m, &n) != -1)
    {
        scanf("%d%d", &a, &b);
		a*=2; b*=2;
        memset(s, 0, sizeof(s));
        memset(e, 0, sizeof(e));
        for (i = 0; i < m; i ++)
        {
            scanf("%d%d", &x, &y);
			if(x&1)x--;
			if(y&1)y++;
            s[x] ++;
            e[y] ++;
        }
        count = 0;
        fill(f, f+n+1, -1);
        for (i = 0; i <= n; i ++)
        {
            count -= e[i];
            if ((count != 0))
                f[i] = maxint32;
            count += s[i];
        }
        f[0] = 0;
		int head = 0, tail=0; 
        j = 0;
        for (i = 2; i <= n; i ++)
            if (f[i] != maxint32)
            {
                while (i - j >= a) //进队列
                {
                    if (f[j] != maxint32)
                    {
                        while (head < tail && f[j] <= f[que[tail-1]])
                            tail --;
						que[tail++] = j;
                    }
                    j +=2;
                }
				//show(que+head, que+tail);
                while (head < tail && i - que[head] > b) //出队列
                    head ++;
                if (head < tail)
                    f[i] = f[que[head]] + 1;
                else
                    f[i] = maxint32;
				//cout<<i<<" "<<( f[i])<<endl;
            }
        if (f[n] == maxint32)
            f[n] = -1;
        printf("%d\n", f[n]);
    }
}

