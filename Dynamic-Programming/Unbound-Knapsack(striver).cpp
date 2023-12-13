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

// Space optimized.
// here is gpt's opinion:
/*
    each iteration of the loop, a new "curr" array is declared and used for the calculations.
    Once the loop iteration is complete, that specific instance of the "curr" array goes out of scope,
    and its memory is deallocated. The next iteration of the loop then declares a fresh "curr" array.

    So, at any given point, you only have two arrays ("prev" and "curr") in memory. 
    The memory for the previous "curr" array is released, and the current "curr" array is reused in the next iteration. 
    This is why it's called a rolling array or rolling DP, as you roll over the array instances.
*/

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w+1, 0));
    //return kev(n-1, w, profit, weight, dp);
    vector<int> prev(w+1, 0);
    for(int i = 0; i <= w; i++){
        prev[i] = (i / weight[0]) * profit[0]; 
    }
    for(int i = 1; i < n; i++){
        vector<int> curr(w+1, 0);
        for(int j = 1; j <= w; j++){
            int not_pick = prev[j];
            int pick = 0;
            if(j >= weight[i]){
                pick = profit[i] + curr[j - weight[i]];
            }
            curr[j] = max(pick, not_pick);
        }
        prev = curr;
    }
    return prev[w];
}

// 1D space optimized , still donno how this works.
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w+1, 0));
    //return kev(n-1, w, profit, weight, dp);
    vector<int> prev(w+1, 0);
    for(int i = 0; i <= w; i++){
        prev[i] = (i / weight[0]) * profit[0]; 
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= w; j++){
            int not_pick = prev[j];
            int pick = 0;
            if(j >= weight[i]){
                pick = profit[i] + prev[j - weight[i]];
            }
            prev[j] = max(pick, not_pick);
        }
    }
    return prev[w];
}
