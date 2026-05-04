class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }
        return splitTree(preorder, inMap, 0, 0, inorder.size() - 1);
    }

private:
    TreeNode* splitTree(vector<int>& preorder, unordered_map<int, int>& inMap, int preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];
        int leftTreeSize = inIndex - inStart;

        root->left = splitTree(preorder, inMap, preIndex + 1, inStart, inIndex - 1);
        root->right = splitTree(preorder, inMap, preIndex + leftTreeSize + 1, inIndex + 1, inEnd);

        return root;
    }
};