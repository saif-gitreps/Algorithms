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
