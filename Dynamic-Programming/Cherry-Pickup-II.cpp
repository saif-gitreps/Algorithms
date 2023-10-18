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
        //kev( 0, 0, m-1, grid, dp);
        for(int i = 0 ; i < m; i ++){
            // copying my similar base case.
            for(int j = 0 ; j < m; j++){
                if(i == j){
                    dp[n-1][i][j] = grid[n-1][i];
                }
                else{
                    dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
                }
            }
        }
        for(int i = n-2; i >= 0; i--){
            for(int c1 = 0; c1 < m; c1++){
                for(int c2 = 0; c2 < m; c2++){
                    int mx = 0;
                    for(int p = -1; p <= 1; p++){
                        int ans;
                        for(int q = -1; q <= 1; q++){
                            if(c1 == c2){
                                ans = grid[i][c1];
                            }
                            else{
                                ans = grid[i][c1] + grid[i][c2];    
                            }    
                            if(c1 + p < m && c2 + q < m && c1 + p >=0 && c2 + q >= 0){
                                ans += dp[i + 1][c1 + p][c2 + q];
                            }
                            else{
                                ans = -1;
                            }
                            mx = max(mx, ans);
                        }
                    }
                    dp[i][c1][c2] = mx;
                }
            }
        }
        return dp[0][0][m-1];

    }
};
