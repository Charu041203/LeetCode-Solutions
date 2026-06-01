class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;
        prefixSums[0] = 1;
        return dfs(root, 0, targetSum, prefixSums);
    }

private:
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSums) {
        if (node == nullptr) {
            return 0;
        }

        currentSum += node->val;
        int count = prefixSums[currentSum - targetSum];

        prefixSums[currentSum]++;
        
        count += dfs(node->left, currentSum, targetSum, prefixSums);
        count += dfs(node->right, currentSum, targetSum, prefixSums);
        
        prefixSums[currentSum]--;
        
        return count;
    }
};