class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;
        backtrack(s, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& s, int index, int dots, string current, vector<string>& result) {
        if (dots == 4) {
            if (index == s.length()) {
                current.pop_back();
                result.push_back(current);
            }
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (index + len > s.length()) {
                break;
            }

            string part = s.substr(index, len);
            if ((part[0] == '0' && len > 1) || (len == 3 && stoi(part) > 255)) {
                continue;
            }

            backtrack(s, index + len, dots + 1, current + part + ".", result);
        }
    }
};