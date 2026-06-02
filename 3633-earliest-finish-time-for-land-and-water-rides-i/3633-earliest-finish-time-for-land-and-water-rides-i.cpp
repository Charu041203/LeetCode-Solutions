#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int landFinish = landStartTime[i] + landDuration[i];
                int waterAfterLand = std::max(landFinish, waterStartTime[j]) + waterDuration[j];
                minFinishTime = std::min(minFinishTime, waterAfterLand);

                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landAfterWater = std::max(waterFinish, landStartTime[i]) + landDuration[i];
                minFinishTime = std::min(minFinishTime, landAfterWater);
            }
        }

        return minFinishTime;
    }
};