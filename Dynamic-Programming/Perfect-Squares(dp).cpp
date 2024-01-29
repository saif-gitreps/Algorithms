class Solution {
// TLE but works.
public:
    bool isPfSquare(int n) {
        int ans = sqrt(n);
        return ans * ans == n;
    }
    int num;
    int kev(int i, int n, vector<vector<int>> &dp) {
        if (n == 0) {
            return 0;
        }
        if (n < 0 || i > num) {
            return 100000;
        }
        if(dp[i][n] != -1){
            return dp[i][n];
        }
        int ans = INT_MAX;
        if (isPfSquare(i)) {
            ans = min(min(1 + kev(i, n - i, dp), kev(i + 1, n, dp)), ans);
        } else {
            ans = min(kev(i + 1, n, dp), ans);
        }
        return dp[i][n] = ans;
    }
    int numSquares(int n) {
        num = n;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return kev(1, n, dp);
    }
};
