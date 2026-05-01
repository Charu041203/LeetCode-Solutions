class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0;
        long long f = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += (long long)i * nums[i];
        }

        long long max_val = f;

        for (int i = n - 1; i > 0; i--) {
            f = f + sum - (long long)n * nums[i];
            max_val = max(max_val, f);
        }

        return (int)max_val;
    }
};