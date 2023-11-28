#include <bits/stdc++.h>
// Using the single cache variable like N was showing the error , so i had to use 2D along wiht Weight var.
int kev(int n, int twt, vector<int> &wt, vector<int> &a, vector<vector<int>> &dp){
	if(n == 0){
		if(twt >= wt[n]){
			return a[n];
		}
		return 0;
	}
	if(n < 0){
		return 0;
	}
	if(dp[n][twt] != -1){
		return dp[n][twt];
	}
	int pick = INT_MIN;
    if (twt >= wt[n]) {
        pick = a[n] + kev(n - 1, twt - wt[n], wt, a, dp);
    }
    int not_pick = kev(n-1, twt, wt, a, dp);
	return dp[n][twt] = max(pick, not_pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp( n, vector<int> (maxWeight+1, -1));
	return kev(n-1, maxWeight, weight, value , dp);
	
}

// tabulation done successfully.
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp( n, vector<int> (maxWeight+1, 0));
	// ok so in tabluation , we need to write nested loops
	// according to the changing parameters, here Wt and N
	// is the changing parameter
	for(int i = 0; i < n; i++){
		for(int w = maxWeight; w >= 0; w--){
			if(i == 0){
				if(w >= weight[i]){
					dp[i][w] = value[i];
				}
				else{
					dp[i][w] = 0;
				}
				continue;
			}
			int not_pick = dp[i-1][w];
			int pick = INT_MIN;
			if(w >= weight[i]){
				pick = dp[i-1][w-weight[i]] + value[i];
			}
			dp[i][w] = max(pick, not_pick);
		}
	}
	return dp[n-1][maxWeight]; 
}
