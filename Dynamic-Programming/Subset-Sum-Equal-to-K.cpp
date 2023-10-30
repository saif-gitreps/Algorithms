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

