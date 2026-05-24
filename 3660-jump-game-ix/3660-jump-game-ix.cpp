class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);
        
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        
        vector<int> ans(n);
        int currentMax = nums[0];
        int lastCut = 0;
        
        for (int i = 0; i < n; ++i) {
            currentMax = max(currentMax, nums[i]);
            if (i == n - 1 || prefixMax[i] <= suffixMin[i + 1]) {
                for (int j = lastCut; j <= i; ++j) {
                    ans[j] = currentMax;
                }
                if (i < n - 1) {
                    currentMax = nums[i + 1];
                    lastCut = i + 1;
                }
            }
        }
        
        return ans;
    }
};