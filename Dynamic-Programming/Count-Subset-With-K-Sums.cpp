problem -> https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbi1aLWVBQUdVbVlTNXJGUy1CVXlzYTRuYmNBQXxBQ3Jtc0tuS2tFSEJFTnZQUmRVZ1lTSWcxdTRPeDl4LVlGejNBWnM5dFlQYzJvWHdxSG9FeVdmXzJGdHI0cnhGci12RzAtNHJ4VWx1ci1fanpIUHFESm5NeUVUbGhac2lfbkZETWJRRHVGWGdMYVVlWHR1aHJUTQ&q=https%3A%2F%2Fbit.ly%2F3B5JBkU&v=ZHyb-A2Mte4
33/50  
int kev(int n, int sum, vector<int> a, vector<vector<int>> &dp){
	if(n < 0){
		return 0;
	}
	if(sum == 0){
		return dp[n][sum] = 1;
	}
	if(n == 0){
		if(sum == a[n]){
			return dp[n][sum] = 1;
		}
		return dp[n][sum] = 0;
	}
	if(dp[n][sum] != -1){
		return dp[n][sum];
	}
	int pick = 0;
	int not_pick = 0;
	if(sum >= a[n]){
		pick = kev(n-1 , sum - a[n], a, dp);
	}
	not_pick = kev(n-1, sum, a, dp);
	return dp[n][sum] = pick + not_pick;
}
int findWays(vector<int>& a, int k){
	int n = a.size();
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	return kev(n-1, k, a, dp);
}
