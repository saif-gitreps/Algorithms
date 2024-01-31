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


class Solution {
// had confusion about the buy as well, just make a loop for all the changing parameters
// and copy the recurrence.
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
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
                        prices[i] + dp[i + 1][1],
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
//bruh understanding the problem is so important, idk why I am so dumb.
//The idea was that :
/*
    It is so simple because you can sell and buy on the same day which means you don't
    need to hold and optimize for the largest profit. Any increase between days is an increment of 
    the maximum profit because of math. 
    (There's also the omniscient ability to "never buy" if the price never goes back up.)

    The idea is that because you can trade multiple times a day at no cost, 
    all you're looking for is if the previous day is worth more than the 
    current day and add their difference to the total profit.
*/
public:
    int n;
    int maxProfit(vector<int>& prices) {
       int profit = 0;
       n = prices.size();
        for(int i=1;i<n;i++) {
            if(prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};
