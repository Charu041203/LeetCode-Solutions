#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> tree;
    int n;

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        n = max_x + 1;
        tree.assign(4 * n, 0);
        
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(n);
        
        update(1, 0, n - 1, 0, n);
        
        vector<bool> results;
        
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.upper_bound(x);
                int next_obs = *it;
                int prev_obs = *prev(it);
                
                obstacles.insert(x);
                
                update(1, 0, n - 1, prev_obs, x - prev_obs);
                update(1, 0, n - 1, x, next_obs - x);
            } else {
                int x = q[1];
                int sz = q[2];
                
                auto it = obstacles.upper_bound(x);
                int prev_obs = *prev(it);
                
                int max_gap = query(1, 0, n - 1, 0, prev_obs - 1);
                max_gap = max(max_gap, x - prev_obs);
                
                results.push_back(max_gap >= sz);
            }
        }
        
        return results;
    }
};