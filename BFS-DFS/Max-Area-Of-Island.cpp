class Solution {
// easy pezee
public:
    int dfs(int i, int j, vector<vector<int>> &a){
        if(i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || a[i][j] == 0){
            return 0;
        }
        a[i][j] = 0;
        int ans = 1;
        ans += dfs(i + 1, j, a);
        ans += dfs(i, j + 1, a);
        ans += dfs(i - 1, j, a);
        ans += dfs(i, j - 1, a);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    mx = max(mx, dfs(i, j, grid));
                }
            }
        }
        return mx;
    }
};
