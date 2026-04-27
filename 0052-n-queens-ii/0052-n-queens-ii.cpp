class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n, false);
        std::vector<bool> diag2(2 * n, false);
        backtrack(0, n, count, cols, diag1, diag2);
        return count;
    }

private:
    void backtrack(int row, int n, int& count, std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n;
            int d2 = row + col;
            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            cols[col] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, count, cols, diag1, diag2);
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};