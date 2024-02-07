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
