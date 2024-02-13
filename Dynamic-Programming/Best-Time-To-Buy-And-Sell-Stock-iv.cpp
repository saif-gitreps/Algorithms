class Solution {
//Similar to the last problem, replace 2 with k.
public:
    int kev(int i, vector<int> a, int buy, int k, vector<vector<vector<int>>> &dp){
        if(k == 0 || i >= a.size()){
            return 0;
        }
        if(dp[i][buy][k] != -1){
            return dp[i][buy][k];
        }
        int profit = INT_MIN;
        if(buy){
            profit = max(
                -a[i] + kev(i + 1, a, 0, k, dp),
                kev(i + 1, a , 1, k, dp)
            );
        }
        else{
            profit = max(
                +a[i] + kev(i + 1, a, 1, k - 1, dp),
                kev(i + 1, a, 0, k, dp)
            );
        }
        return dp[i][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k + 1, -1)));
        return kev(0, prices, 1, k, dp);
    }
};
