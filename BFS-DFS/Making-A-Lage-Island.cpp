class Solution {
// bruteforce attempt, gives TLE.
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<int>> &a) {
        if (i >= n || j >= m || i < 0 || j < 0 || a[i][j] == 0 || vis[i][j]) {
            return 0;
        }
        vis[i][j] = 1;
        return  dfs(i+1, j, n, m, vis, a) +
                dfs(i, j+1, n, m, vis, a) +
                dfs(i-1, j, n, m, vis, a) +
                dfs(i, j-1, n, m, vis, a) + 1;   
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<int>> vis(n, vector<int> (m, 0));
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                    mx = max(mx, dfs(i, j, n, m, vis, grid));
                    grid[i][j] = 0;
                } else {
                    mx = max(mx, dfs(i, j, n, m, vis, grid));
                }
            }
        }

        return mx;   
    }
};
