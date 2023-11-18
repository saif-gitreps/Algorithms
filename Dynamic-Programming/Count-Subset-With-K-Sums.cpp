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

// This was the tabulation method, so apparently my top-down was also correct, theres something wrong with the problem in that site.
int findWays(vector<int>& a, int k) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for(int i = 0 ; i < n ; i++){
        dp[i][0] = 1;
    }
    if(a[0] <= k){
        dp[0][a[0]] = 1;
    }
    for(int i = 1; i <  n ; i++){
        for(int j = k; j >= 0; j--){
            int pick = 0;
            int not_pick = 0;
            not_pick = dp[i-1][j];
            if(a[i] <= j){
                pick = dp[i-1][j-a[i]];
            } 
            dp[i][j] = pick + not_pick;
        }
    }

    return dp[n - 1][k];
}
