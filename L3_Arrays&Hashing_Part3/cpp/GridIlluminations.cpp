
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,0}};

public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<long long, int> m1;  // row number to count of lamps
        unordered_map<long long, int> m2;  // col number to count of lamps
        unordered_map<long long, int> m3;  // diagonal x-y to count of lamps
        unordered_map<long long, int> m4;  // diagonal x+y to count of lamps
        unordered_map<long long, int> m5;  // whether lamp is ON|OFF

        // increment counters while adding lamps
        for (const auto& lamp : lamps) {
            long long x = lamp[0];
            long long y = lamp[1];
            m1[x]++;
            m2[y]++;
            m3[x - y]++;
            m4[x + y]++;
            m5[N * x + y]++;
        }

        vector<int> ans(queries.size());
        // address queries
        for (int i = 0; i < queries.size(); i++) {
            long long x = queries[i][0];
            long long y = queries[i][1];
            ans[i] = (m1[x] > 0 || m2[y] > 0 || m3[x - y] > 0 || m4[x + y] > 0) ? 1 : 0;
            // switch off the lamps, if any
            for (const auto& dir : dirs) {
                long long x1 = x + dir[0];
                long long y1 = y + dir[1];
                if (x1 >= 0 && y1 >= 0 && x1 < N && y1 < N && m5.count(N * x1 + y1)) {
                    int times = m5[N * x1 + y1];
                    m1[x1] -= times;
                    m2[y1] -= times;
                    m3[x1 - y1] -= times;
                    m4[x1 + y1] -= times;
                    m5.erase(N * x1 + y1);
                }
            }
        }

        return ans;
    }
};
