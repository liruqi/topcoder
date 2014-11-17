#include <iostream.h>

int A[1001], d, e, f, g, h;

int modulo(int v, int m)
{
    v=v%m;
    return (v+m)%m;
}

int fy(int i)
{
    int r;
    if(i%2)
    {
         r=(d*A[i-1] + e*A[i-2] - f*A[i-3]) ;
         return modulo(r, g);
    }
    else
    {
        r=(f*A[i-1] - d*A[i-2] + e*A[i-3]) ;
        return modulo(r, h);
    }
}

int main()
{
    int tc, i, j;
	cin>>tc;
    while(tc--)
    {
        cin>>A[0]>>A[1]>>A[2]>>d>>e>>f>>g>>h>>i;
        
        for(j=3; j<=i; j++)
        {
            A[j]=fy(j);
        }
        cout<<A[i]<<endl;
    }
return 0;
}
