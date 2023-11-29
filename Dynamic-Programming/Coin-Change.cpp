class Solution {
// first attempt , worked till 39 cases and showed TLE ,need to do DP on this.
public:
    int ds_size = INT_MAX;
    void kev(int i,long long sum,long long amt,vector<int> &ds,vector<int> &a){
        if(sum>=amt){
            if(sum==amt){
                int n = ds.size();
                ds_size = min(ds_size,n);
            }
            return;
        }
        for(int j = i ;j < a.size(); j++){
            ds.push_back(a[j]);
            sum += a[j];
            kev(j,sum,amt,ds,a);
            sum -= a[j];
            ds.pop_back();
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ds;
        kev(0,0,amount,ds,coins);
        if(ds_size==INT_MAX){
            return -1;
        }
        return ds_size;
    }
};


class Solution {
// this is better recursion.
public:
    int kev(int n, int t, vector<int> a){
       if(t < 0){
           return 1e9;
       }
       if(n == 0){
           if(t % a[n] == 0){
               return t/a[n];
           }
           else{
               return 1e9;
           }
       }
       // if i wont pick that number then i will move ahead.
       int pick = 1 + kev(n, t - a[n], a);
       // if i will pick the number,
       // i will test the limit and stay at the same index(infinte pick).
       int not_pick = kev(n-1, t, a);
       return min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = kev(n-1, amount, coins);
        if(ans == 1e9){
            return -1;
        }
        return ans; 
    }
};


class Solution {
// memoization worked.
public:
    int kev(int n, int t, vector<int> a, vector<vector<int>> &dp){
       if(t < 0){
           return 1e9;
       }
       if(n == 0){
           if(t % a[n] == 0){
               return t/a[n];
           }
           else{
               return 1e9;
           }
       }
       if(dp[n][t] != -1){
           return dp[n][t];
       }
       // if i wont pick that number then i will move ahead.
       int pick = 1 + kev(n, t - a[n], a, dp);
       // if i will pick the number,
       // i will test the limit and stay at the same index(infinte pick).
       int not_pick = kev(n-1, t, a, dp);
       return dp[n][t] = min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, (vector<int> (amount+1, -1)));
        int ans = kev(n-1, amount, coins, dp);
        if(ans == 1e9){
            return -1;
        }
        return ans; 
    }
};


class Solution {
//tabulation method.
public:
    int coinChange(vector<int>& a, int amount) {
        int n = a.size();
        vector<vector<int>> dp(n, (vector<int> (amount+1, 0)));
        //int ans = kev(n-1, amount, coins, dp);

        for(int i = amount; i >= 0; i--){
            if(i % a[0] == 0){
                dp[0][i] = i/a[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }
        for(int i = 1; i < n ; i++){
            for(int val = 0; val <= amount; val++){
                int pick = INT_MAX;
                int not_pick = 0 + dp[i-1][val];
                if(val >= a[i]){
                    pick = 1 + dp[i][val - a[i]];
                }
                dp[i][val] = min(pick, not_pick);
            }
        }
        if(dp[n-1][amount] >= 1e9){
            return -1;
        }
        return dp[n-1][amount]; 
    }
};
