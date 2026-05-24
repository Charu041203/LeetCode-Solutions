class Solution {
public:
    int solve(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        
        int n = arr.size();
        int maxJumps = 1;
        
        for (int j = i + 1; j <= min(i + d, n - 1); ++j) {
            if (arr[j] >= arr[i]) break;
            maxJumps = max(maxJumps, 1 + solve(j, arr, d, dp));
        }
        
        for (int j = i - 1; j >= max(i - d, 0); --j) {
            if (arr[j] >= arr[i]) break;
            maxJumps = max(maxJumps, 1 + solve(j, arr, d, dp));
        }
        
        return dp[i] = maxJumps;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, solve(i, arr, d, dp));
        }
        
        return ans;
    }
};