int kev(int n, int w, vector<int> a, vector<int> weight, vector<vector<int>>& dp){
    // Worked. 
    if(n < 0){
        return 0;
    }
    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    int pick = 0;
    int not_pick = 0;
    if(weight[n] <= w){
        pick = a[n] + kev(n, w - weight[n], a, weight, dp);
    }
    not_pick = kev(n-1, w, a, weight, dp);
    dp[n][w] = max(pick , not_pick);
    return dp[n][w];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w+1, -1));
    return kev(n-1, w, profit, weight, dp);
}
