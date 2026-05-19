class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int totalNumbers = 1 << n;
        result.reserve(totalNumbers);
        
        for (int i = 0; i < totalNumbers; ++i) {
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};