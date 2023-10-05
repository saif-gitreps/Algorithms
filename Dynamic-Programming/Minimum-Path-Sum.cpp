class Solution {
// yay first ever problem solved on my own.
public:
    int kev(int m, int n, vector<vector<int>> &a, vector<vector<int>> &dp){
        if(n == 0 && m==0){
            return dp[m][n] = a[m][n];
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int up = 100000; int left = 100000;
        if( m > 0){
            up = kev(m - 1, n, a, dp) + a[m][n];
        }
        if( n > 0){
            left = kev(m, n - 1, a, dp) + a[m][n];
        }
        return dp[m][n] = min(up , left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        kev(m - 1, n - 1, grid, dp);
        return dp[m-1][n-1];
    }
};
