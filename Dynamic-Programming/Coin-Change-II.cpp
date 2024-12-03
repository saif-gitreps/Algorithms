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


class Solution {
// apparantly its called unbounded knapsack lol.
public:
    int change(int amount, vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, (vector<int> (amount+1, 0)));
        for(int i = amount; i >= 0; i--){
            if(i % a[0] == 0){
                dp[0][i] = 1;
            }
        }
        for(int i = 1; i < n ; i++){
            for(int val = 0; val <= amount; val++){
                int pick = 0;
                int not_pick = 0;
                not_pick = dp[i-1][val];
                if(val >= a[i]){
                    pick = dp[i][val - a[i]];
                }
                dp[i][val] = pick + not_pick;
            }
        }
        return dp[n-1][amount]; 
    }
};

class Solution {
// optimized tabulation . have to study this.
public:
    int change(int amount, vector<int>& coins) {
       vector<int>dp(amount+1);
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
               dp[j]+=dp[j-coins[i]]; 
            }
        }
        return dp[amount];
    }
};


// other attempt

class Solution {
public:
    int kev(int i, int t, vector<int> &a, vector<vector<int>> &dp) {
        if (i < 0 || t < 0) return 0;

        if (t == 0) return 1;

        if (dp[i][t] != -1) return dp[i][t];

        return dp[i][t] = kev(i, t-a[i], a, dp) + kev(i-1, t, a, dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        return kev(coins.size()-1, amount, coins, dp);
    }
};

// this bottom-up should work, but it dosent work for some reason, overflow error ? tf

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int mod = 1e9;
        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1, 0));

        for (int i = 0; i <= coins.size(); i++)
            dp[i][0] = 1;

        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                
                if (j - coins[i - 1] >= 0) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[coins.size()][amount];
    }
};
