class Solution {
public:
    int kev(int n, int c1, int c2, vector<vector<int>> &a, vector<vector<vector<int>>> &dp){
        if(c1<0 || c2<0 || c1>=a[0].size() || c2>=a[0].size() || n == a.size()){
            return -1e8;
        }
        if(n == a.size()- 1){
            if(c1 == c2){
                return a[n][c1];
            }
            return a[n][c1] + a[n][c2];
        }
        if(dp[n][c1][c2] != -1){
            return dp[n][c1][c2];
        }
        int mx = 0;
        for(int i = -1; i <= 1; i++){
            int ans;
            for(int j = -1; j <= 1; j++){
                if(c1 == c2){
                    ans = a[n][c1] + kev(n + 1,c1 + i,c2 + j, a, dp);
                }
                else{
                    ans = (a[n][c1] + a[n][c2]) + kev(n + 1,c1 + i, c2 + j, a, dp);
                }
                mx = max(mx, ans);
            }
        }
        dp[n][c1][c2] = mx;
        return mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m , -1)));
        kev( 0, 0, m-1, grid, dp);
        return dp[0][0][m-1];
    }
};
