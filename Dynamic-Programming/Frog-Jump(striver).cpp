#include <bits/stdc++.h> 

link -> https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// top down approach. TC-> O(n) , SC -> O(n) [for dp array] + O(n) recursion stack.
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

//===============================================================

#include <bits/stdc++.h> 
// tabular method , kind of similar approach , tc-> O(n) . sc-> O(n).
int frogJump(int n, vector<int> &a)
{
    vector<int> dp(n+1,-1);

    dp[0] = 0;
    for(int i = 1 ;i < n ; i ++){
        int step1 = dp[i-1] + abs(a[i] - a[i-1]);
        int step2 = 1000005;
        if(i > 1){
            step2 = dp[i-2] + abs(a[i] - a[i-2]); 
        } 
        dp[i] = min(step1,step2);
    }
    return dp[n-1];
}

//==================================================================
#include <bits/stdc++.h> 

// Tc-> O(n) , SC - > O(1) , the prev and curr method.

int frogJump(int n, vector<int> &a)
{
    vector<int> dp(n+1,-1);
    
    int prev = 0;
    int curr = 0;

    for(int i = 1 ;i < n ; i ++){
        int step1 = curr + abs(a[i] - a[i-1]);
        int step2 = 1000005;
        if(i > 1){
            step2 = prev + abs(a[i] - a[i-2]); 
        } 
        int ans = min(step1,step2);
        prev = curr;
        curr = ans;
    }
    return curr;
}
