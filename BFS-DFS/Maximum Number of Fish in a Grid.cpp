my sol1, accepted, but not the best
```cpp
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &a, int &sum, vector<vector<int>> &vis) {
        if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || a[i][j] == 0 || vis[i][j]) 
            return;

        sum += a[i][j];
        vis[i][j] = 1;

        dfs(i + 1, j, a, sum, vis);
        dfs(i - 1, j, a, sum, vis);
        dfs(i, j + 1, a, sum, vis);
        dfs(i, j - 1, a, sum, vis);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    vector<vector<int>> vis(n, vector<int> (m, 0));
                    int sum = 0;
                    dfs(i, j, grid, sum, vis);
                    mx = max(mx, sum);
                }
            }
        }

        return mx;
    }
};
```

a better solution.

```cpp
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &a) {
        if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || a[i][j] == 0) 
            return 0;

        int sum = a[i][j];
        a[i][j] = 0;

        sum += dfs(i + 1, j, a);
        sum += dfs(i - 1, j, a);
        sum += dfs(i, j + 1, a);
        sum += dfs(i, j - 1, a);

        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    int sum = dfs(i, j, grid);
                    mx = max(mx, sum);
                }
            }
        }

        return mx;
    }
};
```
