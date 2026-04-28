class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int max_prod = nums[0];
        int min_prod = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int current = nums[i];

            if (current < 0) {
                swap(max_prod, min_prod);
            }

            max_prod = max(current, max_prod * current);
            min_prod = min(current, min_prod * current);

            result = max(result, max_prod);
        }
        return result;
    }
};