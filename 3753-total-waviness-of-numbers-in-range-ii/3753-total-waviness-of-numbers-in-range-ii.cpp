class Solution {
public:
    long long dp[20][11][11][2];
    bool vis[20][11][11][2];
    string s;

    pair<long long, long long> dfs(int pos, int prev1, int prev2, bool started, bool tight) {
        if (pos == s.size()) return {1, 0};

        if (!tight && vis[pos][prev1 + 1][prev2 + 1][started])
            return {dp[pos][prev1 + 1][prev2 + 1][started], dp[pos][prev1 + 1][prev2 + 1][started ^ 1]};

        long long cnt = 0, wav = 0;
        int lim = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= lim; d++) {
            bool nt = tight && d == lim;

            if (!started && d == 0) {
                auto [c, w] = dfs(pos + 1, -1, -1, false, nt);
                cnt += c;
                wav += w;
            } else {
                int add = 0;
                if (started && prev2 != -1) {
                    if ((prev1 > prev2 && prev1 > d) || (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                auto [c, w] = dfs(pos + 1, d, started ? prev1 : -1, true, nt);
                cnt += c;
                wav += w + c * add;
            }
        }

        if (!tight) {
            vis[pos][prev1 + 1][prev2 + 1][started] = true;
            dp[pos][prev1 + 1][prev2 + 1][started] = cnt;
            dp[pos][prev1 + 1][prev2 + 1][started ^ 1] = wav;
        }

        return {cnt, wav};
    }

    long long solve(long long x) {
        if (x <= 0) return 0;
        s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return dfs(0, -1, -1, false, true).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};