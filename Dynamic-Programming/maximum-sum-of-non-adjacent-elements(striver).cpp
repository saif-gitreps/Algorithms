#include <bits/stdc++.h>
https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbV9yZ2doRWh0NW9BbnRQbWRQc3ZIeWhrcGRlZ3xBQ3Jtc0ttbjIzaEZ3UTBfdEh0Nmw1dzF3aklLcDJqQkhCbU94TmpRMWtIRXRCR2M4aU04ajhEcVpmLVN3a2VKZmpDT2hQa1p6VnVaMnFjNm5oZjZabkNhdDNEeUVROTNTZGkzRGxnTjQybi1rTkpBYmMtOHFMSQ&q=https%3A%2F%2Fbit.ly%2F3q5rlUY&v=GrMBfJNk_NY
//attempt1 : did it after he explained.

int kev(int n , vector<int> a, vector<int> &dp){
    if(n==0){
        dp[n] = a[n];
        return dp[n];
    }
    if(n < 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int pick = a[n] + kev(n-2,a,dp);
    int not_pick = 0 + kev(n-1,a,dp);

    dp[n] = max(pick,not_pick);
    return dp[n]; 
    
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(),-1);
    kev(nums.size()-1, nums, dp);
    return dp[nums.size()-1];
}
