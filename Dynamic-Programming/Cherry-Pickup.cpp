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


class Solution {
// ultimate solution .
public:
    int cherryPickup(std::vector<std::vector<int>>& grid) {
        int N = grid.size();
        vector<vector<vector<vector<int>>>> dp(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N,vector<int>(N, -1))));
        return std::max(0, cherryPickup(grid, N, 0, 0, 0, 0, dp));
    }

private:
    int cherryPickup(vector<vector<int>>& grid, int n, int r1, int c1, int r2, int c2, vector<vector<vector<vector<int>>>>& dp) {
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }

        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        if (dp[r1][c1][r2][c2] != -1) {
            return dp[r1][c1][r2][c2];
        }

        if (r2 == n - 1 && c2 == n - 1) {
            return grid[r2][c2];
        }

        int cherries;

        if (r1 == r2 && c1 == c2) {
            cherries = grid[r1][c1];
        } else {
            cherries = grid[r1][c1] + grid[r2][c2];
        }

        cherries += max(
            max(cherryPickup(grid, n, r1 + 1, c1, r2 + 1, c2, dp), cherryPickup(grid, n, r1 + 1, c1, r2, c2 + 1, dp)),
            max(cherryPickup(grid, n, r1, c1 + 1, r2 + 1, c2, dp), cherryPickup(grid, n, r1, c1 + 1, r2, c2 + 1, dp))
        );

        dp[r1][c1][r2][c2] = cherries;

        return cherries;
    }

};
