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


class Solution {
public:
    int N;
    int dfs(vector<vector<int>>& grid, int x, int y, int index) {
        if (x < 0 || x >= N || y < 0 || y >= N || grid[x][y] != 1) return 0;
        grid[x][y] = index;
        return 1 + dfs(grid, x + 1, y, index) + dfs(grid, x - 1, y, index) + dfs(grid, x, y + 1, index) + dfs(grid, x, y - 1, index);
    }

    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
        int index = 2, res = 0;
        unordered_map<int, int> area;

        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (grid[x][y] == 1) {
                    area[index] = dfs(grid, x, y, index);
                    res = max(res, area[index++]);
                }
            }
        }

        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (grid[x][y] == 0) {
                    unordered_set<int> seen;
                    int cur = 1;
                    for (auto& dir : vector<vector<int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                        int nx = x + dir[0], ny = y + dir[1];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] > 1 && !seen.count(grid[nx][ny])) {
                            seen.insert(grid[nx][ny]);
                            cur += area[grid[nx][ny]];
                        }
                    }
                    res = max(res, cur);
                }
            }
        }

        return res;
    }
};
