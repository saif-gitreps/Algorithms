class Solution {
// Well it worked , we can do tabulation , space optimization etc.
public:
    int kev(int n, int t, vector<int> a, vector<vector<int>> &dp){
        if(t == 0){
            return 1;
        }
        if(n == 0){
            if(t % a[n] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[n][t] != -1){
            return dp[n][t];
        }
        int pick = 0;
        int not_pick = 0;
        if(t >= a[n]){
            pick = kev(n , t - a[n], a, dp);
        }
        not_pick = kev(n - 1, t, a, dp);
        return dp[n][t] = pick + not_pick;    
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return kev(n-1, amount, coins, dp);
    }
};
