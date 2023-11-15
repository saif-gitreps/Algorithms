// 45/50 cases passed.
int kev(int n, int diff, int sum,vector<int> a, vector<vector<int>> &dp){
	if(n < 0){
		return INT_MAX;
	}
	if(n == 0){
		return min(abs((sum - diff + a[n]) - diff + a[n]), 
		abs((sum - diff) - diff));
	}
	if(dp[n][diff] != -1){
		return dp[n][diff];
	}
	int pick = kev(n-1, diff + a[n], sum, a, dp);
	int not_pick = kev(n-1, diff, sum ,a ,dp);
	return dp[n][diff] = min(pick, not_pick);
}
int minSubsetSumDifference(vector<int>& a, int n){
	long long sum = 0;
	for(int i = 0 ; i < n; i++){
		sum += a[i];
	}
	vector<vector<int>> dp(n, vector<int> (sum+1, -1));
	return kev(n -1 , 0, sum, a, dp);
}
