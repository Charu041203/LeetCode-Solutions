#include <vector>
#include <algorithm>

class Solution {
private:
    struct Ride {
        int start;
        int duration;
    };

    long long solve(const std::vector<int>& start1, const std::vector<int>& dur1, 
                    const std::vector<int>& start2, const std::vector<int>& dur2) {
        int n = start1.size();
        int m = start2.size();
        
        std::vector<Ride> rides2(m);
        for (int i = 0; i < m; ++i) {
            rides2[i] = {start2[i], dur2[i]};
        }
        
        std::vector<int> rideOrder(m);
        std::iota(rideOrder.begin(), rideOrder.end(), 0);
        std::sort(rideOrder.begin(), rideOrder.end(), [&](int a, int b) {
            return rides2[a].start < rides2[b].start;
        });

        std::vector<int> prefMinDur(m);
        prefMinDur[0] = rides2[rideOrder[0]].duration;
        for (int i = 1; i < m; ++i) {
            prefMinDur[i] = std::min(prefMinDur[i - 1], rides2[rideOrder[i]].duration);
        }

        std::vector<long long> suffMinFinish(m);
        suffMinFinish[m - 1] = (long long)rides2[rideOrder[m - 1]].start + rides2[rideOrder[m - 1]].duration;
        for (int i = m - 2; i >= 0; --i) {
            suffMinFinish[i] = std::min(suffMinFinish[i + 1], 
                (long long)rides2[rideOrder[i]].start + rides2[rideOrder[i]].duration);
        }

        std::vector<int> sortedStarts(m);
        for (int i = 0; i < m; ++i) {
            sortedStarts[i] = rides2[rideOrder[i]].start;
        }

        long long minTotalTime = -1;

        for (int i = 0; i < n; ++i) {
            long long finish1 = (long long)start1[i] + dur1[i];
            
            auto it = std::upper_bound(sortedStarts.begin(), sortedStarts.end(), finish1);
            int idx = std::distance(sortedStarts.begin(), it);

            long long currentBest = -1;

            if (idx > 0) {
                currentBest = finish1 + prefMinDur[idx - 1];
            }

            if (idx < m) {
                long long waitOption = suffMinFinish[idx];
                if (currentBest == -1 || waitOption < currentBest) {
                    currentBest = waitOption;
                }
            }

            if (minTotalTime == -1 || currentBest < minTotalTime) {
                minTotalTime = currentBest;
            }
        }

        return minTotalTime;
    }

public:
    int earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, 
                           std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
        long long ans1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        long long ans2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return std::min(ans1, ans2);
    }
};