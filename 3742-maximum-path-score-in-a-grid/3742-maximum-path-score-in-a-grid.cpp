class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int startVal = grid[0][0];
        int startCost = (startVal == 0) ? 0 : 1;
        
        if (startCost <= k) {
            dp[0][0][startCost] = startVal;
        } else {
            return -1;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                int cellVal = grid[i][j];
                int cellCost = (cellVal == 0) ? 0 : 1;

                for (int c = cellCost; c <= k; ++c) {
                    int prevMax = -1;
                    if (i > 0) prevMax = max(prevMax, dp[i - 1][j][c - cellCost]);
                    if (j > 0) prevMax = max(prevMax, dp[i][j - 1][c - cellCost]);

                    if (prevMax != -1) {
                        dp[i][j][c] = prevMax + cellVal;
                    }
                }
            }
        }

        int maxScore = -1;
        for (int c = 0; c <= k; ++c) {
            maxScore = max(maxScore, dp[m - 1][n - 1][c]);
        }

        return maxScore;
    }
};