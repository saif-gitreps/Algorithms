class Solution {
// shows TLE at 46/50
public:
    int kev(int m, int n,vector<vector<int>> a, vector<vector<int>> &dp){
        if(m == a.size()){
            return 0;
        }
        if (dp[m][n] != 1234567) {
        return dp[m][n];
        }
        int left = INT_MAX, mid = INT_MAX, right = INT_MAX;
        if (n > 0) {
            left = kev(m + 1, n - 1, a, dp);
        }
        mid = kev(m + 1, n, a, dp);
        if (n < a[0].size() - 1) {
            right = kev(m + 1, n + 1, a, dp);
        }
        dp[m][n] = a[m][n] + min(left, min(mid, right));
        return dp[m][n];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m ,vector<int> (n, 1234567));
        int ans = 10000;
        for(int j = 0 ; j < n; j++){
            int call = kev(0 , j, matrix,dp); 
            ans = min(call,ans);
        }
        return ans;
    }
};

class Solution {
public:
// tabulation works as well. took me a while to get over my mistakes.
    int minFallingPathSum(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<vector<int>> dp(m ,vector<int> (n, INT_MAX));
        int ans = INT_MAX;
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(i == 0){
                    dp[i][j] = a[i][j];
                }
                else{
                    int left = INT_MAX, mid = INT_MAX, right = INT_MAX;
                    if(j > 0){
                        left = dp[i-1][j-1]; 
                    }
                    if(j + 1 < n ){
                        right = dp[i-1][j+1];
                    }
                    mid = dp[i-1][j];
                    dp[i][j] = a[i][j] + min(mid, min(left ,right));
                }
            }
        }
        ans = dp[m-1][0];
        for(int j = 1; j < n; j++){
            ans = min(dp[m-1][j], ans);
        }
        return ans;
    }
};
