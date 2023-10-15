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


class Solution {
// my attempt. So in MAX function , the recursion call is not made simultaneously.
// When first left is called , when left is exhausted , right is called.
// Also apparently i got TLE if passed a without call by reference. IDK WHAT DIFFERENCE DOES IT MAKE.
public:
    int kev(int n, int row1 , int col1 , int row2 , int col2 , vector<vector<int>> &a,  vector<vector<vector<vector<int>>>> &dp){
        if(row1 >= n || col1 >= n || row2 >= n || col2 >= n || a[row1][col1] ==-1 || a[row2][col2] ==-1){
            return INT_MIN;
        }
        if(row1 == n-1 && col1 == n-1){
            return a[row1][col1];
        }
        if(row2 == n-1 && col2 == n-1){
            return a[row2][col2];
        }
        if(dp[row1][col1][row2][col2] != -1){
            return dp[row1][col1][row2][col2];
        }
        int ans;
        if(row1 == row2 && col1 == col2){
            ans = a[row1][col1];
        }
        else{
            ans = a[row1][col1] + a[row2][col2];
        }
        ans += max(
            max(kev(n, row1 + 1, col1, row2 + 1, col2, a, dp), kev(n, row1 + 1, col1, row2, col2 + 1, a, dp)),
            max(kev(n, row1, col1 + 1, row2 + 1, col2, a, dp), kev(n, row1, col1 + 1, row2, col2 + 1, a, dp))
        );
        dp[row1][col1][row2][col2] = ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>> (n,vector<vector<int>> (n, vector<int> (n, -1))));
        return max(0,kev(n, 0, 0, 0, 0, a, dp));
    }
};
