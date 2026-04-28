class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size();
        int n = grid[0].size();

        int firstRemainder = grid[0][0] % x;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] % x != firstRemainder) {
                    return -1;
                }
                nums.push_back(grid[i][j]);
            }
        }
        size_t midIdx = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + midIdx, nums.end());
        int median = nums[midIdx];

        int totalOps = 0;
        for (int val : nums) {
            totalOps += abs(val - median) / x;
        }
        return totalOps;
    }
};