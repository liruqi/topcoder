#include <iostream>

using namespace std;
int main()
{
    int b,w;
    while(cin>>b>>w)
        {
            int sum = 0;
            if (b==0&&w==0)
                cout << "Impossible" << endl;

            else
            {
                if (b < w)
                    sum = 2*b+1;
                else if (w < b)
                    sum = 2*w+1;
                else if (w = b)
                    sum = w+b;
                int i = 1;
                while (1)
                {
                    if (sum<i*i)
                        {
                            cout << i-1 << endl;
                            break;
                        }
                    else
                        i++;
                }
            }
        }
    return 0;
}