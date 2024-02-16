class Solution {
// EZ problem, just skip 1 extra if you selling das it.
public:
    int n;
    int kev(int i, vector<int> &a, int buy, vector<vector<int>> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = 0;
        if(buy == 1){
            profit = max(
                (-1 * a[i]) + kev(i + 1, a, 0, dp),
                kev(i + 1, a, 1, dp)
            );
        }
        else{
            profit = max(
                a[i] + kev(i + 2, a, 1, dp),
                kev(i + 1, a, 0, dp)
            );
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n , vector<int> (2, -1));
        return kev(0, prices, 1, dp);
    }
};
