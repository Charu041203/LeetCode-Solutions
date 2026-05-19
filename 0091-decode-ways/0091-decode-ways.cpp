class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        int n = s.length();
        int two_back = 1;
        int one_back = 1;
        
        for (int i = 1; i < n; ++i) {
            int current = 0;
            int single_digit = s[i] - '0';
            int double_digit = (s[i - 1] - '0') * 10 + single_digit;
            
            if (single_digit >= 1 && single_digit <= 9) {
                current += one_back;
            }
            
            if (double_digit >= 10 && double_digit <= 26) {
                current += two_back;
            }
            
            if (current == 0) {
                return 0;
            }
            
            two_back = one_back;
            one_back = current;
        }
        
        return one_back;
    }
};