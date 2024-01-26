class Solution {
    private: void bfs(vector < vector < char >> & grid, int i, int j, vector < vector < int >> & vis) {
        vis[i][j] = 1;
        queue < pair < int, int >> q;
        q.push({
            i,
            j
        });
        int row = grid.size();
        int col = grid[0].size();
        int delrow[4] = {
            -1,
            0,
            1,
            0
        };
        int delcol[4] = {
            0,
            1,
            0,
            -1
        };
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newrow = r + delrow[k];
                int newcol = c + delcol[k];

                if (newrow >= 0 && newrow < row && newcol >= 0 && newcol < col && grid[newrow][newcol] == '1' && !vis[newrow][newcol]) {
                    vis[newrow][newcol] = 1;
                    q.push({
                        newrow,
                        newcol
                    });
                }
            }

        }
    }
    public: int numIslands(vector < vector < char >> & grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector < vector < int >> vis(n, vector < int > (m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(grid, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};
