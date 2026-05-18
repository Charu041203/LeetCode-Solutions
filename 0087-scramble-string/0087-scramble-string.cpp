class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (n != s2.length()) return false;
        
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {
                    for (int k = 1; k < len; k++) {
                        if ((dp[k][i][j] && dp[len - k][i + k][j + k]) || 
                            (dp[k][i][j + len - k] && dp[len - k][i + k][j])) {
                            dp[len][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return dp[n][0][0];
    }
};
