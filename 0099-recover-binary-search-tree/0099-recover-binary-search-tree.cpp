class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);

public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        swap(first->val, second->val);
    }

private:
    void traverse(TreeNode* root) {
        if (!root) return;
        
        traverse(root->left);
        
        if (first == nullptr && prev->val > root->val) {
            first = prev;
        }
        if (first != nullptr && prev->val > root->val) {
            second = root;
        }
        prev = root;
        
        traverse(root->right);
    }
};