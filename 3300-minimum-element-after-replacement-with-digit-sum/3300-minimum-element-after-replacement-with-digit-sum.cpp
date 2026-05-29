class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        for (int num : nums) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            min_val = min(min_val, sum);
        }
        return min_val;
    }
};