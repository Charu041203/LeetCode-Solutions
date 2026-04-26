class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> last_seen_mirror;
        int min_dist = -1;
        
        for (int j = 0; j < nums.size(); ++j) {
            if (last_seen_mirror.count(nums[j])) {
                int dist = j - last_seen_mirror[nums[j]];
                if (min_dist == -1 || dist < min_dist) {
                    min_dist = dist;
                }
            }
            
            last_seen_mirror[reverseNum(nums[j])] = j;
        }
        
        return min_dist;
    }

private:
    int reverseNum(int n) {
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return (int)rev;
    }
};