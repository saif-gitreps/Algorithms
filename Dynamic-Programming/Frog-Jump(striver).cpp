#include <bits/stdc++.h> 
// top down approach. TC-> O(n) , SC -> O(n) [for dp array].
int kev(int n,vector<int> &a,vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int step1 = kev(n-1,a,dp) + abs(a[n] - a[n-1]);
    int step2 = INT_MAX;
    if(n>1){
        step2 = kev(n-2,a,dp) + abs(a[n] - a[n-2]);
    }
    dp[n] = min(step1,step2);
    return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return kev(n-1,heights,dp);
}
