class Solution {
// similar to II , but minus the fee.
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int> (2, -1));
        dp[n][1] = 0;
        dp[n][0] = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= 1; j++){
                int profit = 0;
                if(j){
                    profit = max(
                        (-1*prices[i]) + dp[i + 1][0],
                        dp[i + 1][1]
                    );
                }
                else{
                    profit = max(
                        (prices[i] - fee) + dp[i + 1][1],
                        dp[i + 1][0]
                    );
                }
                dp[i][j] = profit;
            }
        } 
        return dp[0][1];
    }
};

class Solution {
SC close to constant.
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<int> curr(2, 0);
        vector<int> ahead(2, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= 1; j++){
                int profit = 0;
                if(j){
                    profit = max(
                        (-1*prices[i]) + ahead[0],
                        ahead[1]
                    );
                }
                else{
                    profit = max(
                        (prices[i] - fee) + ahead[1],
                        ahead[0]
                    );
                }
                curr[j] = profit;
            }
            ahead = curr;
        } 
        return curr[1];
    }
};
