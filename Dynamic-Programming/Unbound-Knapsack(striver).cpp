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

//Tabulation works 100% (Y) 

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w+1, 0));
    //return kev(n-1, w, profit, weight, dp);
    for(int i = 0; i <= w; i++){
        dp[0][i] = (i / weight[0]) * profit[0]; 
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= w; j++){
            int not_pick = dp[i-1][j];
            int pick = 0;
            if(j >= weight[i]){
                pick = profit[i] + dp[i][j - weight[i]];
            }
            dp[i][j] = max(pick, not_pick);
        }
    }
    return dp[n-1][w];
}
