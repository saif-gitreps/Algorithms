class Solution {
/*
  The proof is that, no matter how big of an island there is, we at max only need 2 days to make the number of island to more than 1.
  00000000
  00111100
  00111100
  00111100
  00000000

  int this example, it looks like we need 4 days to make it into 2, but actually, take 2 diagonals from the side, and the 
  days is 2.
*/
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& a, vector<vector<int>> &vis) {
        if (i < 0 || j < 0 || i >= m || j >= n || a[i][j] == 0 || vis[i][j]) return;
        vis[i][j] = 1;
        dfs(i + 1, j, m, n, a, vis);
        dfs(i - 1, j, m, n, a, vis);
        dfs(i, j + 1, m, n, a, vis);
        dfs(i, j - 1, m, n, a, vis);
    }

    int minDays(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<vector<int>> vis;
        vis.resize(m, (vector<int> (n, 0)));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1 && !vis[i][j]) {
                    dfs(i , j, m, n, a, vis);
                    count++;
                }
            }
        }
        if (count != 1) return 0; // either we have many islands, or no islands.

        vector<pair<int, int>> rc;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) rc.push_back({i, j});
            }
        }

        for (auto p : rc) {
            fill(vis.begin(), vis.end(), vector<int>(n, 0));
            a[p.first][p.second] = 0;
            count = 0;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 1 && !vis[i][j]) {
                        dfs(i, j, m, n, a, vis);
                        count++;            
                    }
                }
            }

            if (count != 1) return 1;
            a[p.first][p.second] = 1;
        }

        return 2;
    }
};
