#include <bits/stdc++.h> 
// naive bruteforce attempt.
int kev(int n, vector<int> &a, int k, vector<int> &dp){
   if(k == 0){
      return true;
   }
   if(n == 0){
      if(k == a[n]){
         return true;
      }
      return false;
   }
   int not_pick = false;
   int pick = false;
   not_pick = kev(n-1, a, k, dp);
   if(k >= a[n]){
      pick = kev(n-1, a, k - a[n], dp);
   }
   return not_pick || pick;
}

bool subsetSumToK(int n, int k, vector<int> &nums) {
    vector<int> dp(n, -1);
    return kev(n-1, nums, k, dp);
}


#include <bits/stdc++.h> 
// Memoized solution , works.
int kev(int n,vector<int> &a,int k,vector<vector<int>> &dp){
   if(k == 0){
      return true;
   }
   if(n == 0){
      if(k == a[n]){
         return true;
      }
      return false;
   }
   if(dp[n][k] != -1){
       return dp[n][k];
   }
   int not_pick = false;
   int pick = false;
   not_pick = kev(n-1, a, k, dp);
   if(k >= a[n]){
      pick = kev(n-1, a, k - a[n], dp);
   }
   return dp[n][k] = not_pick || pick;
}

bool subsetSumToK(int n, int k, vector<int> &nums) {
    vector<vector<int>> dp(n, vector<int> (10001, -1));	
    //ok so I had confusion in terms of what to memoize, so apparently 
    //we have to memoize, the changing states, we have to check all the variables that are 
    //changing and we have to memoize that for. ex , here k and n are changing, in that cherry pickup 
    //we had three variables changing so we memorized all three variables.
    //so we check all the changing variables and then make a dp array, possibly 2D 3D, and store them.
    return kev(n-1, nums, k, dp);
}


bool subsetSumToK(int n, int k, vector<int> &nums) {
    vector<vector<int>> dp(n, vector<int> (k+1, false));
    /*
    For writing tablution
    step1: declare the same dp array.
    step2: figure out the base case , here it says that,
    no matter what the index, if k == 0 then we set it to true,
    so what you're going to do is loop from 1-N and set all true for k==0.
    Here k == a[n] means that we can k - a[n] == 0.
    it means if choosing a[n] will result your k to be 0 or no.
    */
    if (nums[0] <= k) {
        dp[0][nums[0]] = true;
    }
    for(int i = 0; i < n; i++){
       dp[i][0] = true;
    }
    for(int i = 1; i < n; i++){
       for (int j = 1; j <= k; j++) {
         int pick = false;
         int not_pick = false;
         if(j >= nums[i]){
            pick = dp[i - 1][j - nums[i]];
         }
         not_pick = dp[i - 1][j];
         dp[i][j] = pick || not_pick;
       }
    }
    return dp[n-1][k];
}
