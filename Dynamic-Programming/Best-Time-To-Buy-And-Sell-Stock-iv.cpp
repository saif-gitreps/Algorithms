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


class Solution {
// tabulation works.
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (k + 1, 0)));
        
        dp[n][1][0] = 0;
        dp[n][0][0] = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int buy = 1; buy >= 0; buy --){
                for(int left = k; left >= 1; left--){
                    int profit = INT_MIN;
                    if(buy){
                        profit = max(
                            -prices[i] + dp[i + 1][0][left],
                            dp[i + 1][1][left]
                        );
                    }
                    else{
                        profit = max(
                            +prices[i] + dp[i + 1][1][left - 1],
                            dp[i + 1][0][left]
                        );
                    }
                    dp[i][buy][left] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int> (k * 2 + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 0; trans < k * 2 ; trans++) {
                if (trans % 2 == 0) { 
                    dp[ind][trans] = max(
                        dp[ind + 1][trans],
                        -prices[ind] + dp[ind + 1][trans + 1]
                    );
                }
                else {
                    dp[ind][trans] = max(
                        dp[ind + 1][trans],
                        prices[ind] + dp[ind + 1][trans + 1]
                    );
                }
            }
        }
        return dp[0][0];
    }
};
