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

class solutuon{
// successfully did tabulation as well. 
public:
  int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int up = 100000; int left = 100000; 
                    if(i > 0){
                        up = dp[i-1][j] + grid[i][j];
                    }
                    if(j > 0){
                        left = dp[i][j-1] + grid[i][j];
                    }
                    dp[i][j] = min(up , left);
                }
            }
        }
        return dp[m-1][n-1];
    }
}

class Solution {
// space optimized.
// basic logic being that we store the values of each rows in a prev, we calculate a curr for at present. 
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<int> prev(n, 0);
        for(int i = 0 ; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[i][j];
                }
                else{
                    int up = 100000; int left = 100000; 
                    if(i > 0){
                        up = prev[j] + grid[i][j];
                    }
                    if(j > 0){
                        left = curr[j-1] + grid[i][j];
                    }
                    curr[j] = min(up , left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
