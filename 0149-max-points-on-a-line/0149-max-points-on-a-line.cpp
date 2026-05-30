#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int globalMax = 2;

        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slopeMap;
            int localMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = abs(dy);
                }

                string slope = to_string(dy) + "/" + to_string(dx);
                slopeMap[slope]++;
                localMax = max(localMax, slopeMap[slope]);
            }
            
            globalMax = max(globalMax, localMax + 1);
        }

        return globalMax;
    }
};