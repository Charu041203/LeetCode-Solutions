class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int currentStreamNum = 1;
        
        for (int i = 0; i < target.size(); ++i) {
            while (currentStreamNum < target[i]) {
                result.push_back("Push");
                result.push_back("Pop");
                currentStreamNum++;
            }
            
            result.push_back("Push");
            currentStreamNum++;
        }
        
        return result;
    }
};