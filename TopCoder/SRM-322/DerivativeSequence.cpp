#include <vector>
#include <string>
using namespace std;

struct DerivativeSequence {
    public:
        vector<int> derSeq(vector<int> a, int n) {
            vector<int> b;
            for (int i=0;i<n;i++)
            {
                b.clear();
                for (int j=0;j<a.size()-1;j++)
                    b.push_back(a[j+1]-a[j]);
                a = b;
            }
            return a;

        }

}

;
