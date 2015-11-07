
#include <set>
#include <map>
#include <vector>

using namespace std;


class Solution {
public:
    int cooList[20000];
    int skyline[20000];
    vector<pair<int, int> > getSkyline(vector < vector<int> > & buildings) {
        set<int> cooSet;
        for (int i=0; i<buildings.size(); i++) {
            cooSet.insert(buildings[i][0]);
            cooSet.insert(buildings[i][1]);
        }
        map<int,int> cooIdx;
        int N = cooSet.size();
        int it = 0;
        for (set<int>::iterator itg = cooSet.begin(); itg != cooSet.end(); ++itg) {
            cooList[it] = *itg;
            cooIdx[*itg] = it;
            it ++;
        }
        for (int i=0; i<buildings.size(); i++) {
            int left = cooIdx[ buildings[i][0] ];
            int rt = cooIdx[ buildings[i][1] ];
            for (int p=left; p<rt; p++) {
                skyline[p] = std::max(skyline[p], buildings[i][2]);
            }
        }
        int coo = -1;
        // int h = 0;
        vector<pair<int, int> > ret;
        for (int p=0; p<N; p++) {
            if (coo == -1) {
                if (skyline[p]==0) {
                    continue;
                } else {
                    coo = p;
                    continue;
                }
            }
            
            if (skyline[coo] == skyline[p]) continue;
            
            pair<int, int> kp = make_pair(cooList[coo], skyline[coo]);
            coo = p;
            // h = skyline[p];
            ret.push_back(kp);
        }
        if (coo >= 0) {
            pair<int, int> kp = make_pair(cooList[coo], skyline[coo]);
            ret.push_back(kp);
        }
        return ret;
    }
};
