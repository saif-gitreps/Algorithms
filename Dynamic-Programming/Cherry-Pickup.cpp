class Solution {
// tried something , doesnt work , has too many flaws.
public:
    int rev(int m, int n,vector<vector<int>> a, vector<vector<int>> &dp){
        if(m == 0 && n == 0){
            return dp[m][n] = a[m][n];
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        if(a[m][n] == -1){
            return dp[m][n] = 0;
        }
        int left = INT_MIN;
        int up = INT_MIN;
        if(a[m][n] == 1){
            a[m][n] = 0;
            if(n > 0){
                left = kev(m, n - 1, a, dp) + 1;
            }
            if(m > 0){
                up = kev(m - 1, n, a, dp) + 1;
            }
            a[m][n] = 1;
        }
        else{
            if(n > 0){
                left = kev(m, n - 1, a, dp);
            }
            if(m > 0){
                up = kev(m - 1, n, a, dp);
            }
        }
        return dp[m][n] = max(up,left);
    }
    int kev(int m, int n,vector<vector<int>> &a, vector<vector<int>> &dp){
        if(m == a.size()-1 && n == a[0].size()-1){
            vector<vector<int>> dp2;
            return dp[m][n] = rev( m-1, n-1, a, dp2);
        }
        if(n + 1 >= a.size() || m + 1 >= a[0].size()){
            return 0;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        if(a[m][n] == -1){
            return dp[m][n] = 0;
        }
        int right = INT_MIN;
        int down = INT_MIN;
        if(a[m][n] == 1){
            a[m][n] = 0;
            //if(n + 1 < a.size()){
                right = kev(m, n +1, a, dp) + 1;
            //}
            //if(m + 1 < a[0].size()){
                down = kev(m +1, n, a, dp) + 1;
            //}
            a[m][n] = 1;
        }
        else{
            //if(n + 1 < a.size()){
                right = kev(m, n +1, a, dp);
            //}
            //if(m + 1 < a[0].size()){
                down = kev(m +1, n, a, dp);
            //}
        }
        return dp[m][n] = max(right,down);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int> (n, -1));
        kev(0, 0, grid, dp);
        if(dp[m-1][n-1] == -1){
            return 0;
        }
        return dp[0][0];
    }
};
