int kev(int i, int index_sum,vector<int> a, vector<vector<int>> &dp){
  // just another unbound type of problem, i wont write space or tabulation for this.
	if(i == 0){
		if(index_sum % (i+1) == 0){
			return index_sum / (i+1) * a[i];
		}
		else{
			return 0;
		}
	}
	if(dp[i][index_sum] != -1){
		return dp[i][index_sum];
	}
	int pick = INT_MIN;
    if (index_sum >= (i + 1)) {
		pick = a[i] + kev(i, index_sum - (i + 1), a, dp);
    }
    int not_pick = kev(i - 1, index_sum, a, dp);
	return dp[i][index_sum] = max(pick, not_pick);
}

int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n,vector<int> (n+1, -1));
	return kev(n-1, n, price, dp);
}
