#include<bits/stdc++.h> 
https://atcoder.jp/contests/dp/tasks/dp_b
// tablution TC -> O(N * k) SC - > O(n)

using namespace std;

int main(){
   int n,k;
   cin>>n>>k;
   int a[n] = {0};
   for(int i = 0; i < n ; i ++){
      cin>>a[i];
   }
   int dp[n+1];
   memset(dp, -1 , sizeof(dp));
   dp[0] = 0;
   for(int i = 1 ; i < n ; i ++){
      int min_jump = INT_MAX;
      for(int j = 1; j <= k; j++){
        if( i - j >= 0){
          int jump = dp[i-j] + abs(a[i] - a[i-j]);
          min_jump = min(min_jump,jump);
        }
      }
      dp[i] = min_jump; 
   }
   cout<<dp[n-1];
}


//==========================================================


#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
    // Base case: If we are at the beginning (index 0), no cost is needed.
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];
    int mmSteps = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (ind - j >= 0) {
            // Calculate the cost for this jump and update mmSteps with the minimum cost
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = min(jump, mmSteps);
        }
    }
    return dp[ind] = mmSteps;
}
int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1); 
    return solveUtil(n - 1, height, dp, k);
}

