class Solution {
// works , my intuition to have another transaction vairable was correct
// missed the execution idea of only decreasing transaction if and only if i am planning to sell the stock.
public:
    int n;
    int kev(int i, vector<int> &a, int buy, vector<vector<vector<int>>> &dp, int trans){
        if(trans == 0){
            return 0;
        }
        if(i == n){
            return 0;
        }
        if(dp[i][buy][trans] != -1){
            return dp[i][buy][trans];
        }
        int profit = 0;
        if(buy == 1){
            profit = max(
                (-1 * a[i]) + kev(i + 1, a, 0, dp, trans),
                kev(i + 1, a, 1, dp, trans)
            );
        }
        else{
            profit = max(
                a[i] + kev(i + 1, a, 1, dp, trans - 1),
                kev(i + 1, a, 0, dp, trans)
            );
        }
        return dp[i][buy][trans] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
       // vector<vector<int>> dp(n , vector<int> (2, -1));
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3,-1)));
        return kev(0, prices, 1, dp, 2);

    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 0) { 
                        dp[ind][buy][cap] = max(
                            0 + dp[ind + 1][0][cap],
                            -prices[ind] + dp[ind + 1][1][cap]
                        );
                    }

                    if (buy == 1) {
                        dp[ind][buy][cap] = max(
                            0 + dp[ind + 1][1][cap],
                            prices[ind] + dp[ind + 1][0][cap - 1]
                        );
                    }
                }
            }
        }

    return dp[0][0][2];

    }
};
