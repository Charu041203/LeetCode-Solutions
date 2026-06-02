#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::queue<std::pair<int, int>> q;
        int freshOranges = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        
        if (freshOranges == 0) return 0;
        
        int minutes = 0;
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int size = q.size();
            bool rottedAny = false;
            
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                for (const auto& dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        freshOranges--;
                        rottedAny = true;
                    }
                }
            }
            
            if (rottedAny) {
                minutes++;
            }
        }
        
        return freshOranges == 0 ? minutes : -1;
    }
};