class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for (const auto& d : descriptions) {
            int parentVal = d[0];
            int childVal = d[1];
            bool isLeft = d[2];

            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            if (isLeft) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }

            children.insert(childVal);
        }

        for (const auto& d : descriptions) {
            int parentVal = d[0];
            if (children.find(parentVal) == children.end()) {
                return nodeMap[parentVal];
            }
        }

        return nullptr;
    }
};