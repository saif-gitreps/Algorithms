class Solution {
// I need to concentrate more on solving these types of problems.
// the key idea that i was missing was how to buy and how to sell.
// also i didnt understand the problem statment as well i thought i had to buy only 2 stock at max.
public:
    int n;
    int kev(int i, vector<int> &a, int buy, vector<vector<int>> &dp){
        if(i == n){
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
                a[i] + kev(i + 1, a, 1, dp),
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
