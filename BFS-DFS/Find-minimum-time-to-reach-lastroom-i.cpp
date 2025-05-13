class Solution {
// TLE
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int mn = INT_MAX;

    void kev(int i, int j, vector<vector<int>>& a, vector<vector<int>>& vis, int t) {
        int n = a.size();
        int m = a[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j])
            return;

        if (i == n - 1 && j == m - 1) {
            mn = min(mn, t);
            return;
        }

        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj]) {
                int wait = max(0, a[ni][nj] - t);
                kev(ni, nj, a, vis, t + wait + 1); 
            }
        }

        vis[i][j] = 0;
    }

    int minTimeToReach(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        kev(0, 0, a, vis, 0);
        return mn;
    }
};
